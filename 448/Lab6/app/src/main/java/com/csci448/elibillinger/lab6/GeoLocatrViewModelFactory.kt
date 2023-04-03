package com.csci448.elibillinger.lab6

import android.content.Context
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider

class GeoLocatrViewModelFactory(private val context: Context) : ViewModelProvider.NewInstanceFactory() {
    fun getViewModelClass() = GeoLocatrViewModel::class.java
    override fun <T : ViewModel> create(modelClass: Class<T>): T {
        if( modelClass.isAssignableFrom(getViewModelClass()) )
            return modelClass.getConstructor(WeatherRepository::class.java).newInstance(WeatherRepository.getInstance(context))
        throw IllegalArgumentException("Unknown ViewModel")
    }
}