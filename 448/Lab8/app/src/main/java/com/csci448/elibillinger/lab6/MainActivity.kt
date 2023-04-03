package com.csci448.elibillinger.lab6

import android.app.PendingIntent
import android.app.TaskStackBuilder
import android.content.Context
import android.content.Intent
import android.location.Location
import android.os.Bundle
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Surface
import androidx.compose.runtime.*
import androidx.compose.runtime.livedata.observeAsState
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalLifecycleOwner
import androidx.compose.ui.tooling.preview.Preview
import androidx.core.net.toUri
import androidx.lifecycle.Lifecycle
import androidx.lifecycle.flowWithLifecycle
import androidx.navigation.NavHostController
import androidx.navigation.NavType
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController
import androidx.navigation.navArgument
import androidx.navigation.navDeepLink
import com.csci448.elibillinger.lab6.ui.theme.Lab6Theme
import com.csci448.elibillinger.lab6.util.DataStoreManager
import com.csci448.elibillinger.lab6.util.LocationNotificationUtility
import com.google.android.gms.maps.CameraUpdateFactory
import com.google.android.gms.maps.model.CameraPosition
import com.google.android.gms.maps.model.LatLng
import com.google.android.gms.maps.model.LatLngBounds
import com.google.maps.android.compose.rememberCameraPositionState
import kotlinx.coroutines.launch

class MainActivity : ComponentActivity() {

    private lateinit var locationUtility: LocationUtility
    private val BASE_URI = "https://geolocatr.csci448.edu"

    companion object{
        private val BASE_URI = "https://geolocatr.csci448.edu"
        public fun createPendingIntent(context: Context, location: Location): PendingIntent{
            val deepLinkIntent = Intent(Intent.ACTION_VIEW,
                "$BASE_URI/${location.latitude}/${location.longitude}".toUri(),
                context,
                MainActivity::class.java
            )
            val deepLinkPendingIntent = TaskStackBuilder.create(context).run {
                addNextIntentWithParentStack(deepLinkIntent)
                getPendingIntent(0, PendingIntent.FLAG_UPDATE_CURRENT or
                        PendingIntent.FLAG_IMMUTABLE)
            }
            return deepLinkPendingIntent
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        locationUtility = LocationUtility(this)
        setContent {
            Lab6Theme {
                // A surface container using the 'background' color from the theme
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colors.background
                ) {

                    val navController = rememberNavController()
                    NavHost(navController = navController as NavHostController, startDestination = "location?lat={lat}&long={long}"){
                        //get location

                        composable(route = "location?lat={lat}&long={long}",
                                arguments = listOf(
                                navArgument( name = "lat" ) {
                                    type = NavType.StringType
                                    nullable = true
                                }, navArgument( name = "long" ) {
                            type = NavType.StringType
                            nullable = true
                        }
                        ),
                        deepLinks = listOf( navDeepLink { uriPattern = "$BASE_URI/{lat}/{long}" } ) ){

                            it.arguments?.let { args ->
                                val lat = args.getString("lat")?.toDouble()
                                val long = args.getString("long")?.toDouble()
                                Log.d("TAG",lat.toString())
                                Log.d("TAG",long.toString())
                                if (lat != null && long != null ) {
                                    Location("").apply {
                                        latitude = lat
                                        longitude = long
                                        locationUtility.viewModel.currentLocationLiveData.value = this
                                    }
                                    Log.d("TAG",locationUtility.viewModel.currentLocationLiveData.value.toString())
                                }
                            }



                            val locationState = locationUtility.viewModel.currentLocationLiveData.observeAsState()
                            val addressState = locationUtility.viewModel.currentAddressLiveData.observeAsState("")
                            val dataStoreManager = DataStoreManager(this@MainActivity)
                            val lifecycleOwner = LocalLifecycleOwner.current
                            val doNotificationFlowLifecycleAware = remember(dataStoreManager.doNotificationFlow,lifecycleOwner) {
                                dataStoreManager.doNotificationFlow.flowWithLifecycle(lifecycleOwner.lifecycle,Lifecycle.State.STARTED)
                            }
                            val notificationState by doNotificationFlowLifecycleAware.collectAsState(
                                initial = false
                            )
                            val coroutineScope = rememberCoroutineScope()
                            val onMapReadyState = remember{mutableStateOf(false)}
                            val cameraPositionState = rememberCameraPositionState {
                                position = CameraPosition.fromLatLngZoom(LatLng(0.0,0.0), 0f)
                            }
                            LaunchedEffect(locationState.value, onMapReadyState.value) {
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
                                    if(onMapReadyState.value) {
                                        cameraPositionState.animate(cameraUpdate)
                                    }

                                    //fire notification
                                    locationState.value?.let { location ->
                                        LocationNotificationUtility.pushNotification(this@MainActivity,location)
                                    }
                                }
                            }
                            LocationScreen(
                                locationState = locationState,
                                addressState = addressState,
                                onGetLocation = { locationUtility.checkPermissionAndGetLocation(this@MainActivity) },
                                cameraPositionState = cameraPositionState,
                                notificationState = notificationState,
                                toggleNotification = {coroutineScope.launch { dataStoreManager.setDoNotification(!notificationState) }},
                                onMapReadyState = onMapReadyState

                            )
                        }
                    }





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