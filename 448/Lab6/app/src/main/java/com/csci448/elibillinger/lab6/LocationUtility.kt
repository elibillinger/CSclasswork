package com.csci448.elibillinger.lab6

import android.Manifest
import android.annotation.SuppressLint
import kotlin.text.StringBuilder
import android.content.Context
import android.content.pm.PackageManager
import android.location.Geocoder
import android.location.Location
import android.os.Looper
import android.util.Log
import android.widget.Toast
import androidx.activity.ComponentActivity
import androidx.activity.result.ActivityResultLauncher
import androidx.activity.result.contract.ActivityResultContracts
import androidx.core.app.ActivityCompat
import androidx.lifecycle.ViewModelProvider
import com.google.android.gms.location.*
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory
import java.io.IOException

class LocationUtility(activity: ComponentActivity,viewModelGeo: GeoLocatrViewModel) {
    public val viewModel = viewModelGeo
    private val fusedLocationProviderClient: FusedLocationProviderClient =
        LocationServices.getFusedLocationProviderClient(activity)

    private val permissionLauncher: ActivityResultLauncher<Array<String>> =
        activity.registerForActivityResult(ActivityResultContracts.RequestMultiplePermissions())
        { isGrantedMap ->
            var hasEnoughPermissions = false
            isGrantedMap.forEach{ (perm,isGranted) ->
                hasEnoughPermissions = hasEnoughPermissions || isGranted
            }
            if (hasEnoughPermissions){
                getLocation()
            }
        }

    fun checkPermissionAndGetLocation(activity: ComponentActivity){
        if (activity.checkSelfPermission(Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED
        || activity.checkSelfPermission(Manifest.permission.ACCESS_COARSE_LOCATION) == PackageManager.PERMISSION_GRANTED)
        {
            getLocation()
        } else {
            if(ActivityCompat.shouldShowRequestPermissionRationale(activity,Manifest.permission.ACCESS_COARSE_LOCATION)){
                Toast
                    .makeText(activity, R.string.location_reason_message, Toast.LENGTH_SHORT)
                    .show()
            } else {
                permissionLauncher.launch(arrayOf(Manifest.permission.ACCESS_FINE_LOCATION,Manifest.permission.ACCESS_COARSE_LOCATION))
            }
        }
    }


    private fun getAddress(context: Context, location: Location?): String {
        if(location == null) return ""

        val geocoder = Geocoder(context)
        val addressTextBuilder = StringBuilder()
        try {
            val addresses = geocoder.getFromLocation(location.latitude,
                location.longitude,
                1)
            if(addresses != null && addresses.isNotEmpty()) {
                val address = addresses[0]
                for(i in 0..address.maxAddressLineIndex) {
                    if(i > 0) {
                        addressTextBuilder.append( "\n" )
                    }
                    addressTextBuilder.append( address.getAddressLine(i) )
                }
            }
        } catch (e: IOException) {
            //Log.e("Test", "Error getting address: ${e.localizeMessage}")
        }
        return addressTextBuilder.toString()
    }

    fun getAddressForCurrentLocation(context: Context) {
        viewModel.currentAddressLiveData.value =
            getAddress(context, viewModel.currentLocationLiveData.value)
    }


    init {
//        val factory = GeoLocatrViewModelFactory()
//        viewModel = ViewModelProvider(activity, factory)[factory.getViewModelClass()]
    }

    private val locationRequest = LocationRequest.create().apply { interval = 0
        numUpdates = 1
        priority = LocationRequest.PRIORITY_HIGH_ACCURACY}


    private val locationCallback = object : LocationCallback() {
        override fun onLocationResult(locationResult: LocationResult) {
            super.onLocationResult(locationResult)
            Log.d("test", "Got a location: ${locationResult.lastLocation}")
            viewModel.currentLocationLiveData.value = locationResult.lastLocation
            getWeather(locationResult.lastLocation)
        }
    }

    @SuppressLint("MissingPermission")
    private fun getLocation(){
        fusedLocationProviderClient.requestLocationUpdates(locationRequest,locationCallback, Looper.getMainLooper())
    }

    fun removeLocationRequest() {
        fusedLocationProviderClient.removeLocationUpdates(locationCallback)
    }
}

fun getWeather(location: Location) {
    var weatherString = ""
    val retrofit = Retrofit.Builder()
        .baseUrl("http://api.openweathermap.org/")
        .addConverterFactory(GsonConverterFactory.create())
        .build()
    val service = retrofit.create(WeatherService::class.java)
    val call = service.getCurrentWeatherData(location.latitude.toString(), location.longitude.toString(), "e6562ffcc0905b85d993106380d9f76e")
    call.enqueue(object : Callback<WeatherResponse> {
        override fun onResponse(call: Call<WeatherResponse>, response: Response<WeatherResponse>) {
            Log.d("TAG","test")
            if (response.code() == 200) {
                val weatherResponse = response.body()!!

                val stringBuilder = "Country: " +
                        weatherResponse.sys!!.country +
                        "\n" +
                        "Temperature: " +
                        weatherResponse.main!!.temp +
                        "\n" +
                        "Temperature(Min): " +
                        weatherResponse.main!!.temp_min +
                        "\n" +
                        "Temperature(Max): " +
                        weatherResponse.main!!.temp_max +
                        "\n" +
                        "Humidity: " +
                        weatherResponse.main!!.humidity +
                        "\n" +
                        "Pressure: " +
                        weatherResponse.main!!.pressure

                //weatherData!!.text = stringBuilder
                Log.d("TAG",weatherResponse.main!!.temp.toString())
                weatherString = stringBuilder
            }
        }

        override fun onFailure(call: Call<WeatherResponse>, t: Throwable) {
            //weatherData!!.text = t.message
        }
    })
}