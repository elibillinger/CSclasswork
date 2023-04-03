package com.csci448.elibillinger.lab6

import android.location.Location
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel

class GeoLocatrViewModel(private val weatherRepository: WeatherRepository):ViewModel() {
    val currentLocationLiveData =  MutableLiveData<Location?>(null)
    val currentAddressLiveData = MutableLiveData<String>("")

    fun addWeatherInfo(weatherInfo: WeatherInfo){
        weatherRepository.addWeatherInfo(weatherInfo)
    }
}