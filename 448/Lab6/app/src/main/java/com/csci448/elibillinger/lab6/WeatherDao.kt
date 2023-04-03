package com.csci448.elibillinger.lab6

import androidx.room.Dao
import androidx.room.Insert

@Dao
interface WeatherDao {
    @Insert
    fun addWeatherInfo(weatherInfo: WeatherInfo)
}