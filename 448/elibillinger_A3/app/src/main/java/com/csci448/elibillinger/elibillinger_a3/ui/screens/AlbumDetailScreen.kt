package com.csci448.elibillinger.elibillinger_a3.ui.screens

import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material.Divider
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.csci448.elibillinger.elibillinger_a3.R
import com.csci448.elibillinger.elibillinger_a3.data.DiscoAlbum
import com.csci448.elibillinger.elibillinger_a3.data.DiscoTrack
import com.csci448.elibillinger.elibillinger_a3.ui.theme.Purple500


@Composable
private fun AlbumMainDetails(title: String, artist: String, year: String){
    Column(horizontalAlignment = Alignment.CenterHorizontally){
        Text(text = artist, fontSize = 28.sp, color = Purple500)
        Text(text = title, fontSize = 24.sp)
        Text(text = year, fontSize = 24.sp)
        Divider(thickness = 2.dp, color = Purple500)
    }
}

@Composable
private fun DisplayTracksBSide(track: DiscoTrack){
    Column(horizontalAlignment = Alignment.CenterHorizontally) {
        Text(text = stringResource(id = R.string.album_side_B))
        Row {
                Text(text = track.trackNum.toString())
                Spacer(modifier = Modifier.width(20.dp))
                Text(text = track.title)
                Spacer(modifier = Modifier.weight(1f))

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
}

@Composable
private fun DisplayTracksASide(track: DiscoTrack){
    Column(horizontalAlignment = Alignment.CenterHorizontally) {
        Text(text = stringResource(id = R.string.album_side_A))
        Row {
            Text(text = track.trackNum.toString())
            Spacer(modifier = Modifier.width(20.dp))
            Text(text = track.title)
            Spacer(modifier = Modifier.weight(1f))
            Text(text = stringResource(R.string.time_formatter).format(track.lengthMin.toString(),track.lengthSec.toString()))
        }
    }
}

@Composable
public fun AlbumDetailScreen(album : DiscoAlbum, tracks: MutableList<DiscoTrack>) {
    Column(Modifier.padding(16.dp)) {
        AlbumMainDetails(title = album.title, artist = album.artist, year = album.year.toString())
        LazyColumn {
            items(tracks) { track ->
                if (track.albumID == album.id){
                    if(track.albumSide){
                        DisplayTracksASide(track)
                    } else {
                        DisplayTracksBSide(track)
                    }
                }
            }
        }
    }
}
