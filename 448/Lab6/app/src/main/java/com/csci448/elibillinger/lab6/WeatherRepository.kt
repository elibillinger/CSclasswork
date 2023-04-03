package com.csci448.elibillinger.lab6

import android.content.Context
import java.util.concurrent.Executors

class WeatherRepository private constructor(private val weatherDao: WeatherDao){
    companion object{
        @Volatile private var INSTANCE: WeatherRepository? = null
        fun getInstance(context: Context): WeatherRepository {
            synchronized(this) {
                var instance = INSTANCE
                if(instance == null) {
                    val database = WeatherDatabase.getInstance(context)
                    instance = WeatherRepository(database.weatherDao)
                    INSTANCE = instance
                }
                return instance
            }
        }
    }

    private val executor = Executors.newSingleThreadExecutor()

    fun addWeatherInfo(weatherInfo: WeatherInfo){
        executor.execute {
            weatherDao.addWeatherInfo(weatherInfo)
        }
    }

}