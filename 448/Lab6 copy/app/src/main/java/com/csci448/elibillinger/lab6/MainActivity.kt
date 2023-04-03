package com.csci448.elibillinger.lab6

import android.location.Location
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Surface
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.livedata.observeAsState
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.saveable.rememberSaveable
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.tooling.preview.Preview
import com.csci448.elibillinger.lab6.ui.theme.Lab6Theme
import com.google.android.gms.maps.CameraUpdateFactory
import com.google.android.gms.maps.model.CameraPosition
import com.google.android.gms.maps.model.LatLng
import com.google.android.gms.maps.model.LatLngBounds
import com.google.maps.android.compose.rememberCameraPositionState

class MainActivity : ComponentActivity() {

    private lateinit var locationUtility: LocationUtility

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
                    LocationScreen(
                        locationState = locationState,
                        addressState = addressState,
                        onGetLocation = { locationUtility.checkPermissionAndGetLocation(this) },
                        cameraPositionState = cameraPositionState
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