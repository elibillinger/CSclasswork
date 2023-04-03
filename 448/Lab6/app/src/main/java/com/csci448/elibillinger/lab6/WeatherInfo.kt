package com.csci448.elibillinger.lab6

import androidx.room.Entity
import androidx.room.PrimaryKey
import java.io.Serializable
import java.util.*

@Entity(tableName = "weather")
class WeatherInfo (val latitude: Float,
                   val longitude: Float,
                   val address: String,
                   val datetime: String,
                   val temp: String,
                   val weatherDescription: String){
    @PrimaryKey var id: UUID = UUID.randomUUID()
}