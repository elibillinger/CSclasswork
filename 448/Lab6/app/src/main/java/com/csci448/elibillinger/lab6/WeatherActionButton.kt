package com.csci448.elibillinger.lab6

import android.location.Location
import android.util.Log
import androidx.compose.material.*
import androidx.compose.runtime.Composable
import androidx.compose.runtime.State
import androidx.compose.ui.res.painterResource
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.launch
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory
import java.time.LocalDateTime
import java.time.format.DateTimeFormatter
import java.time.format.FormatStyle

@Composable
fun WeatherActionButton(getWeather: () -> Unit,
                        scaffoldState: ScaffoldState,
                        coroutineScope: CoroutineScope,
                        viewModel: GeoLocatrViewModel,
                        locationState : State<Location?>,
                        addressState: State<String>){

    FloatingActionButton(onClick = {
        getWeather()
        } ) {
        Icon(painter = painterResource(id = R.drawable.ic_baseline_my_location_24), contentDescription = "Get Location")
    }

}

public fun makeSnackBar(scaffoldState: ScaffoldState,
                 coroutineScope: CoroutineScope,
                 viewModel: GeoLocatrViewModel,
                 locationState : State<Location?>,
                 addressState: State<String>){

    val currentTime = LocalDateTime.now()
    val formatter = DateTimeFormatter.ofLocalizedDateTime(FormatStyle.MEDIUM)
    val formattedTime = currentTime.format(formatter)

    var weatherString = ""
    var latitude = 0.0f
    var longitude = 0.0f
    locationState.value?.let {
        latitude = it.latitude.toFloat()
        longitude = it.longitude.toFloat()
    }
    //save to database
    val weatherData = WeatherInfo(latitude = latitude,longitude,addressState.value,formattedTime,"","")
    viewModel.addWeatherInfo(weatherData)

    coroutineScope.launch {
        val snackbarResult = scaffoldState.snackbarHostState.showSnackbar(
            message = "You were here: $formattedTime \n Temp:",
            duration = SnackbarDuration.Long,
            actionLabel = "DELETE"
        )
        when(snackbarResult) {
            SnackbarResult.Dismissed -> { /* snackbar went away */ }
            SnackbarResult.ActionPerformed -> {  }
        }
    }
}





