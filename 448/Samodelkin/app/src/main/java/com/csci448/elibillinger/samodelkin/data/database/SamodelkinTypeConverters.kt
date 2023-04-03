package com.csci448.elibillinger.samodelkin.data.database

import androidx.room.TypeConverter
import java.util.*

class SamodelkinTypeConverters {

    @TypeConverter
    fun fromUUID(uuid: UUID?) = uuid?.toString()

    @TypeConverter
    fun toUUID(uuidString: String?) = UUID.fromString(uuidString)

}