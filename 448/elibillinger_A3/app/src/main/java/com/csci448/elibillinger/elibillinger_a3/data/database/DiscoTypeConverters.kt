package com.csci448.elibillinger.elibillinger_a3.data.database

import androidx.room.TypeConverter
import java.util.*

class DiscoTypeConverters {
    @TypeConverter
    fun fromUUID(uuid: UUID?) = uuid?.toString()

    @TypeConverter
    fun toUUID(uuidString: String?) = UUID.fromString(uuidString)
}