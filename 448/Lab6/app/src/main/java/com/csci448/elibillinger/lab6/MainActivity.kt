package com.csci448.elibillinger.lab6

import android.location.Location
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.material.*
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.rounded.Menu
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.livedata.observeAsState
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.rememberCoroutineScope
import androidx.compose.runtime.saveable.rememberSaveable
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.lifecycle.ViewModelProvider
import androidx.navigation.compose.rememberNavController
import com.csci448.elibillinger.lab6.ui.theme.Lab6Theme
import com.google.android.gms.maps.CameraUpdateFactory
import com.google.android.gms.maps.model.CameraPosition
import com.google.android.gms.maps.model.LatLng
import com.google.android.gms.maps.model.LatLngBounds
import com.google.maps.android.compose.rememberCameraPositionState
import kotlinx.coroutines.launch
import retrofit2.Retrofit

class MainActivity : ComponentActivity() {

    private lateinit var locationUtility: LocationUtility
    private lateinit var viewModel: GeoLocatrViewModel

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val factory = GeoLocatrViewModelFactory(this)
        viewModel = ViewModelProvider(this,factory).get(factory.getViewModelClass())
        locationUtility = LocationUtility(this,viewModel)



        setContent {
            Lab6Theme {
                // A surface container using the 'background' color from the theme
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colors.background
                ) {

                    val navController = rememberNavController()
                    val locationState = locationUtility.viewModel.currentLocationLiveData.observeAsState()
                    val addressState = locationUtility.viewModel.currentAddressLiveData.observeAsState("")
                    val cameraPositionState = rememberCameraPositionState {
                        position = CameraPosition.fromLatLngZoom(LatLng(0.0,0.0), 0f)
                    }
                    LaunchedEffect(locationState.value) {
                        locationUtility.getAddressForCurrentLocation(this@MainActivity)

                        // create a point for the corresponding lat/long
                        val locationPosition = locationState.value?.let {
                            LatLng(it.latitude, it.longitude)
                        }
                        if(locationPosition != null) {
                            // include all points that should be within the bounds of the zoom
                            // convex hull
                            val bounds = LatLngBounds.Builder()
                                .include(locationPosition)
                                .build()
                            // add padding
                            //val padding = LocalContext.current.resources.getDimensionPixelSize(R.dimen.map_inset_padding)
                            // create a camera to smoothly move the map view
                            val cameraUpdate = CameraUpdateFactory.newLatLngBounds(bounds,100)
                            // move our camera!
                            cameraPositionState.animate(cameraUpdate)
                        }
                    }
                    val scaffoldState = rememberScaffoldState()
                    val coroutineScope = rememberCoroutineScope()

                    Scaffold(
                        scaffoldState = scaffoldState,
                        topBar = { TopAppBar(title = { Text(text = "WeathrTrackr") },
                                navigationIcon = { IconButton(onClick = { coroutineScope.launch { scaffoldState.drawerState.open() } },) {
                                        Icon(Icons.Rounded.Menu, contentDescription = "") } }) },

                        drawerContent ={
                            Text("WeathrTrackr")
                            Divider()
                            Spacer(modifier = Modifier.height(20.dp))
                            Card(modifier = Modifier.clickable { navController.navigate("map") }) {
                                Text("Map")
                            }
                            Spacer(modifier = Modifier.height(20.dp))
                            Divider()
                            Spacer(modifier = Modifier.height(20.dp))
                            Card(modifier = Modifier.clickable { navController.navigate("history") }) {
                                Text("History")
                            }
                            Spacer(modifier = Modifier.height(20.dp))
                            Divider()
                            Spacer(modifier = Modifier.height(20.dp))
                            Card(modifier = Modifier.clickable { navController.navigate("settings") }) {
                                Text("Settings")
                            }
                            Spacer(modifier = Modifier.height(20.dp))
                            Divider()
                            Spacer(modifier = Modifier.height(20.dp))
                            Card(modifier = Modifier.clickable { navController.navigate("about") }) {
                                Text("About")
                            }
                            Spacer(modifier = Modifier.height(20.dp))
                        },

                        content = { WeatherNavHost(
                            locationState = locationState,
                            onGetLocation = { locationUtility.checkPermissionAndGetLocation(this) },
                            addressState = addressState,
                            cameraPositionState = cameraPositionState,
                            scaffoldState = scaffoldState,
                            coroutineScope = coroutineScope,
                            navController = navController,
                            viewModel = viewModel
                        )},
                        floatingActionButton = {
                            WeatherActionButton(
                                getWeather = { locationUtility.checkPermissionAndGetLocation(this) },
                                scaffoldState = scaffoldState,
                                coroutineScope = coroutineScope,
                                viewModel = viewModel,
                                locationState = locationState,
                                addressState = addressState
                            )
                        }
                    )

                }
            }
        }
    }


    override fun onStop() {
        super.onStop()
        locationUtility.removeLocationRequest()
    }
}


@Preview(showBackground = true)
@Composable
fun DefaultPreview() {
    Lab6Theme {

    }
}