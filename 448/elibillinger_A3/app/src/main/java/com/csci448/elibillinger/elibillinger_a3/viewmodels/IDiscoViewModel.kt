package com.csci448.elibillinger.elibillinger_a3.viewmodels

import androidx.lifecycle.LiveData
import androidx.lifecycle.ViewModel
import com.csci448.elibillinger.elibillinger_a3.data.DiscoAlbum
import com.csci448.elibillinger.elibillinger_a3.data.DiscoTrack
import java.util.*

abstract class IDiscoViewModel: ViewModel() {

    abstract val albumListLiveData: LiveData<MutableList<DiscoAlbum>>
    abstract val trackListLiveData: LiveData<MutableList<DiscoTrack>>
    abstract val albumLiveData: LiveData<DiscoAlbum?>

    abstract fun loadAlbum(id: UUID)
    abstract fun addAlbum(album: DiscoAlbum)
    abstract fun addTrack(track: DiscoTrack)
}