package com.csci448.elibillinger.lab6

import android.location.Location
import android.util.Log
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material.Button
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.MutableState
import androidx.compose.runtime.State
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.saveable.rememberSaveable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.google.android.gms.maps.model.LatLng
import com.google.maps.android.compose.CameraPositionState
import com.google.maps.android.compose.GoogleMap
import com.google.maps.android.compose.Marker

@Composable
fun LocationScreen(locationState : State<Location?>,
                   onGetLocation: () -> Unit,
                   addressState: State<String>,
                   cameraPositionState: CameraPositionState,
                   notificationState: Boolean,
                   toggleNotification: () -> Unit,
                   onMapReadyState: MutableState<Boolean>){

    var latitude = ""
    var longitude = ""
    var address = ""
    Column(modifier = Modifier
        .padding(16.dp)
        .fillMaxSize(), horizontalAlignment = Alignment.CenterHorizontally) {
        //Notification Button
        Button(onClick = toggleNotification) {
            if(notificationState){
                Text(text = stringResource(id = R.string.turn_notifications_off_label))
            } else {
                Text(text = stringResource(id = R.string.turn_notifications_on_label))
            }
        }

        Text(text = "Latitude / Longitude")
        locationState.value?.let {
            latitude = it.latitude.toString()
            longitude = it.longitude.toString()
        }
        Text(text = "$latitude / $longitude")
        Text(text = "Address")
        address = addressState.value
        Text(text = address)
        Button(onClick = onGetLocation) {
            Text("Get Current Location")
        }


        val locationPosition = locationState.value?.let {
            LatLng(it.latitude, it.longitude)
        } ?: LatLng(0.0, 0.0)

        GoogleMap(
            modifier = Modifier.fillMaxSize(),
            cameraPositionState = cameraPositionState,
            onMapLoaded = {onMapReadyState.value = true}
        ) {
            locationState.value?.let {
                if(it.latitude != 0.0 && it.longitude != 0.0){
                    Marker(
                        position = locationPosition,
                        title = addressState.value,
                        snippet = "$latitude / $longitude"
                    )
                }
            }
        }
    }
}


//@Preview(showBackground = true)
//@Composable
//private fun PreviewLocationScreen() {
//    val locationState = rememberSaveable { mutableStateOf<Location?>(null) }
//    val addressState = rememberSaveable { mutableStateOf("") }
//    LocationScreen(
//        locationState = locationState,
//        addressState = addressState,
//        onGetLocation = {
//            locationState.value = Location("").apply {
//                latitude = 1.35
//                longitude = 103.87
//            }
//            addressState.value = "Singapore"
//        }
//    )
//}