package com.csci448.elibillinger.elibillinger_a3.ui.screens

import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material.Divider
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.unit.dp
import com.csci448.elibillinger.elibillinger_a3.R
import com.csci448.elibillinger.elibillinger_a3.data.DiscoAlbum
import com.csci448.elibillinger.elibillinger_a3.data.DiscoTrack
import com.csci448.elibillinger.elibillinger_a3.ui.theme.Purple500

@Composable
private fun TrackRow(track: DiscoTrack, album: DiscoAlbum){
    //Display each track w/ track title, artist, album title, and track time
    Column {
        Row(modifier = Modifier
            .fillMaxSize()
            .padding(vertical = 10.dp)) {
            Spacer(modifier = Modifier.width(10.dp))
            Column(modifier = Modifier.width(80.dp)) {
                Text(text = track.title)
            }
            Spacer(modifier = Modifier.width(20.dp))
            Column(modifier = Modifier.width(80.dp)) {
                Text(text = album.artist)
            }
            Spacer(modifier = Modifier.width(20.dp))
            Column(modifier = Modifier.width(80.dp)) {
                //determine what side the track is on and display that with album title
                val side: String
                if(track.albumSide){
                    side = "A"
                } else {
                    side = "B"
                }
                Text(text = stringResource(id = R.string.album_side_formatter).format(album.title,side))
            }
            Spacer(modifier = Modifier.width(20.dp))
            Column(modifier = Modifier.width(50.dp)) {
                //add zero for seconds if the amount of seconds is less than 10
                val lengthSec: String
                if(track.lengthSec < 10){
                    lengthSec = "0" + track.lengthSec.toString()
                } else {
                    lengthSec = track.lengthSec.toString()
                }
                Text(text = stringResource(R.string.time_formatter).format(track.lengthMin.toString(),lengthSec))
            }
        }
        Divider(thickness = 2.dp, color = Purple500)
    }


}

@Composable
fun TrackListScreen(tracks: List<DiscoTrack>,albums: List<DiscoAlbum>){
    LazyColumn {
        items(tracks) { track ->
            //pass the corresponding album for each track to get artist and album title
            albums.forEach{
                if(it.id == track.albumID){
                    TrackRow(track = track, album = it)
                }
            }

        }
    }
}