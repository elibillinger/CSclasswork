package com.csci448.elibillinger.elibillinger_a3.data.database

import androidx.lifecycle.LiveData
import androidx.room.Dao
import androidx.room.Insert
import androidx.room.Query
import com.csci448.elibillinger.elibillinger_a3.data.DiscoAlbum
import com.csci448.elibillinger.elibillinger_a3.data.DiscoTrack
import java.util.*

@Dao
interface DiscoDao {

    @Insert
    fun addAlbum(album: DiscoAlbum)
    @Insert
    fun addTrack(track: DiscoTrack)
    @Query("SELECT * FROM album")
    fun getAlbums(): LiveData<MutableList<DiscoAlbum>>
    @Query("SELECT * FROM album WHERE id=(:id)")
    fun getAlbum(id: UUID) : LiveData<DiscoAlbum?>
    @Query("SELECT * FROM track")
    fun getTracks() : LiveData<MutableList<DiscoTrack>>
}