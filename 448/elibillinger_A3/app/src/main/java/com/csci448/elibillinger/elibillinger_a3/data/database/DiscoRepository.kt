package com.csci448.elibillinger.elibillinger_a3.data.database

import android.content.Context
import androidx.lifecycle.LiveData
import com.csci448.elibillinger.elibillinger_a3.data.DiscoAlbum
import com.csci448.elibillinger.elibillinger_a3.data.DiscoTrack
import java.util.*
import java.util.concurrent.Executors

class DiscoRepository private constructor(private val discoDao: DiscoDao) {
    companion object{
        @Volatile private var INSTANCE: DiscoRepository? = null
        fun getInstance(context: Context): DiscoRepository {
            synchronized(this) {
                var instance = INSTANCE
                if(instance == null) {
                    val database = DiscoDatabase.getInstance(context)
                    instance = DiscoRepository(database.discoDao)
                    INSTANCE = instance
                }
                return instance
            }
        }
    }

    private val executor = Executors.newSingleThreadExecutor()

    fun addAlbum(album: DiscoAlbum){
        executor.execute {
            discoDao.addAlbum(album)
        }
    }

    fun addTrack(track: DiscoTrack){
        executor.execute {
            discoDao.addTrack(track)
        }
    }

    fun getAlbums(): LiveData<MutableList<DiscoAlbum>> = discoDao.getAlbums()
    fun getAlbum(id: UUID): LiveData<DiscoAlbum?> = discoDao.getAlbum(id)
    fun getTracks(): LiveData<MutableList<DiscoTrack>> = discoDao.getTracks()
}