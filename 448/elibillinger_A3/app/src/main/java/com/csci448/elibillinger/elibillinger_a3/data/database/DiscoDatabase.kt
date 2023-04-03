package com.csci448.elibillinger.elibillinger_a3.data.database

import android.content.Context
import androidx.room.Database
import androidx.room.Room
import androidx.room.RoomDatabase
import androidx.room.TypeConverters
import com.csci448.elibillinger.elibillinger_a3.data.DiscoAlbum
import com.csci448.elibillinger.elibillinger_a3.data.DiscoTrack

@Database(entities = [DiscoAlbum::class, DiscoTrack::class], version = 1)
@TypeConverters(DiscoTypeConverters::class)
abstract class DiscoDatabase : RoomDatabase() {
    companion object {
        @Volatile private var INSTANCE: DiscoDatabase? = null
        fun getInstance(context: Context): DiscoDatabase {
            synchronized(this) {
                var instance = INSTANCE
                if(instance == null) {
                    instance = Room.databaseBuilder(context, DiscoDatabase::class.java,
                        "disco-database").build()
                    INSTANCE = instance
                }
                return instance
            }
        }
    }

    abstract val discoDao: DiscoDao
}