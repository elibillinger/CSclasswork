package com.csci448.elibillinger.lab6

import androidx.room.TypeConverter
import java.util.*

class WeatherTypeConverters {

    @TypeConverter
    fun fromUUID(uuid: UUID?) = uuid?.toString()

    @TypeConverter
    fun toUUID(uuidString: String?) = UUID.fromString(uuidString)
}