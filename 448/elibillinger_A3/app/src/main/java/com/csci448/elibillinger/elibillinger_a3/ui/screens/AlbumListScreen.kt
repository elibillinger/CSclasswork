package com.csci448.elibillinger.elibillinger_a3.ui.screens

import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material.Card
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.csci448.elibillinger.elibillinger_a3.data.DiscoAlbum

@Composable
private fun AlbumRow(album: DiscoAlbum,
                         onSelectAlbum: (DiscoAlbum) -> Unit){
    Card(modifier = Modifier
        .padding(start = 16.dp, end = 16.dp, top = 8.dp, bottom = 8.dp)
        .clickable { onSelectAlbum(album) }
        .fillMaxSize()
    ){
        Row {
            Text(text = album.artist, fontSize = 24.sp)
            Spacer(modifier = Modifier.weight(1f))
            Column(horizontalAlignment = Alignment.End) {
                Text(text = album.title)
                Text(text = album.year.toString())
            }
        }
    }
}

@Composable
fun AlbumListScreen(albums: List<DiscoAlbum>,
                        onSelectAlbum: (DiscoAlbum) -> Unit){
    LazyColumn {
        items(albums) { DiscoAlbum ->
            AlbumRow(album = DiscoAlbum, onSelectAlbum = onSelectAlbum)
        }
    }
}