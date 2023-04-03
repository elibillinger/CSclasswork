package com.csci448.elibillinger.elibillinger_a3.viewmodels

import android.content.Context
import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.Transformations
import com.csci448.elibillinger.elibillinger_a3.data.DiscoAlbum
import com.csci448.elibillinger.elibillinger_a3.data.DiscoTrack
import com.csci448.elibillinger.elibillinger_a3.data.database.DiscoRepository
import java.util.*

class DiscoViewModel(private val discoRepository: DiscoRepository, context: Context) : IDiscoViewModel()  {

    override val albumListLiveData = discoRepository.getAlbums()
    override val trackListLiveData = discoRepository.getTracks()
    private val _albumIDLiveData = MutableLiveData<UUID>()

    //get the album from the databse by its ID
    override val albumLiveData: LiveData<DiscoAlbum?> =
        Transformations.switchMap(_albumIDLiveData) { albumID ->
            discoRepository.getAlbum(albumID)
        }


    //set the id to find it in the database
    override fun loadAlbum(id:UUID) {
        _albumIDLiveData.value = id
    }

    //add album to database
    override fun addAlbum(album: DiscoAlbum) {
        discoRepository.addAlbum(album)
    }

    // add track to database
    override fun addTrack(track: DiscoTrack) {
        discoRepository.addTrack(track)
    }
}