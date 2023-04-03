package com.csci448.elibillinger.samodelkin.data.database

import android.content.Context
import androidx.room.Database
import androidx.room.Room
import androidx.room.RoomDatabase
import androidx.room.TypeConverters
import com.csci448.elibillinger.samodelkin.data.SamodelkinCharacter

@Database(entities = [SamodelkinCharacter::class], version = 1)
@TypeConverters(SamodelkinTypeConverters::class)
abstract class SamodelkinDatabase : RoomDatabase() {
    companion object {
        @Volatile private var INSTANCE: SamodelkinDatabase? = null
        fun getInstance(context: Context): SamodelkinDatabase {
            synchronized(this) {
                var instance = INSTANCE
                if(instance == null) {
                    instance = Room.databaseBuilder(context, SamodelkinDatabase::class.java,
                        "samodelkin-database").build()
                    INSTANCE = instance
                }
                return instance
            }
        }
    }

    abstract val samodelkinDao: SamodelkinDao
}