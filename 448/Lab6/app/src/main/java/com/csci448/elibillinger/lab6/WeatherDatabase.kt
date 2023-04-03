package com.csci448.elibillinger.lab6

import android.content.Context
import androidx.room.Database
import androidx.room.Room
import androidx.room.RoomDatabase
import androidx.room.TypeConverters

@Database(entities = [WeatherInfo::class], version = 1)
@TypeConverters(WeatherTypeConverters::class)
abstract class WeatherDatabase : RoomDatabase() {
    companion object {
        @Volatile private var INSTANCE: WeatherDatabase? = null
        fun getInstance(context: Context): WeatherDatabase {
            synchronized(this) {
                var instance = INSTANCE
                if(instance == null) {
                    instance = Room.databaseBuilder(context, WeatherDatabase::class.java,
                        "weather-database").build()
                    INSTANCE = instance
                }
                return instance
            }
        }
    }

    abstract val weatherDao: WeatherDao
}