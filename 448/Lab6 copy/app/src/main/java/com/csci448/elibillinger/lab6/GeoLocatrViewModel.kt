package com.csci448.elibillinger.lab6

import android.location.Location
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel

class GeoLocatrViewModel: ViewModel() {
    val currentLocationLiveData =  MutableLiveData<Location?>(null)
    val currentAddressLiveData = MutableLiveData<String>("")
}