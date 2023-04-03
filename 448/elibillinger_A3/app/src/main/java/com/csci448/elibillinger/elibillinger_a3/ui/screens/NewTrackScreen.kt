package com.csci448.elibillinger.elibillinger_a3.ui.screens

import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.selection.selectableGroup
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.material.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.text.input.KeyboardType
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.csci448.elibillinger.elibillinger_a3.R
import com.csci448.elibillinger.elibillinger_a3.data.DiscoAlbum
import com.csci448.elibillinger.elibillinger_a3.data.DiscoTrack
import com.csci448.elibillinger.elibillinger_a3.ui.theme.Purple500


@Composable
private fun AlbumMainDetails(title: String, artist: String, year: String){
    //Header displaying album details
    Column(horizontalAlignment = Alignment.CenterHorizontally){
        Text(text = artist, fontSize = 28.sp, color = Purple500)
        Text(text = title, fontSize = 24.sp)
        Text(text = year, fontSize = 24.sp)
        Divider(thickness = 2.dp, color = Purple500)
    }
}

@Composable
fun AddTrackScreen(album: DiscoAlbum, onClick: (DiscoTrack) -> Unit){
    //Values to store text field inputs
    var trackNumber by remember { mutableStateOf("") }
    var title by remember { mutableStateOf("") }
    var lengthMins by remember { mutableStateOf("") }
    var lengthSecs by remember { mutableStateOf("") }
    var side by remember { mutableStateOf(true)}
    var allFilled : Boolean
    Column (horizontalAlignment = Alignment.CenterHorizontally,modifier = Modifier.padding(horizontal = 30.dp)) {
        //Create all text input fields
        AlbumMainDetails(title = album.title, artist = album.artist, year = album.year.toString())
        LazyColumn (modifier = Modifier.padding(vertical = 10.dp),horizontalAlignment = Alignment.CenterHorizontally){
            item {
                Row (verticalAlignment = Alignment.CenterVertically) {
                    Text(text = stringResource(R.string.add_track_num), modifier = Modifier.width(100.dp), fontSize = 14.sp)
                    Spacer(modifier = Modifier.width(2.dp))
                    OutlinedTextField(value = trackNumber, keyboardOptions = KeyboardOptions(keyboardType = KeyboardType.Number),
                        onValueChange = {trackNumber = it})
                }
                Row (verticalAlignment = Alignment.CenterVertically) {
                    Text(text = stringResource(R.string.add_track_title), modifier = Modifier.width(100.dp), fontSize = 14.sp)
                    Spacer(modifier = Modifier.width(2.dp))
                    OutlinedTextField(value = title,
                        onValueChange = {title = it})
                }
                Row (verticalAlignment = Alignment.CenterVertically) {
                    Text(text = stringResource(R.string.add_track_length_min), modifier = Modifier.width(100.dp), fontSize = 14.sp)
                    Spacer(modifier = Modifier.width(2.dp))
                    OutlinedTextField(value = lengthMins, keyboardOptions = KeyboardOptions(keyboardType = KeyboardType.Number),
                        onValueChange = {lengthMins = it})
                }
                Row (verticalAlignment = Alignment.CenterVertically) {
                    Text(text = stringResource(R.string.add_track_length_sec), modifier = Modifier.width(100.dp), fontSize = 14.sp)
                    Spacer(modifier = Modifier.width(2.dp))
                    OutlinedTextField(value = lengthSecs, keyboardOptions = KeyboardOptions(keyboardType = KeyboardType.Number),
                        onValueChange = {lengthSecs = it})
                }
                Row {
                    Text(text = stringResource(R.string.add_track_side), fontSize = 14.sp)
                    Spacer(modifier = Modifier.width(150.dp))
                    Row(Modifier.selectableGroup()) {
                        RadioButton(selected = side, onClick = { side = true})
                        Text(text = "A")
                        Spacer(modifier = Modifier.width(10.dp))
                        RadioButton(selected = !side, onClick = { side = false })
                        Text(text = "B")
                        Spacer(modifier = Modifier.width(4.dp))
                    }
                }

                Spacer(modifier = Modifier.height(20.dp))

                //check if all fields have been filled
                allFilled = trackNumber != "" && lengthMins != "" && lengthSecs != "" && title != ""

                //create the track object
                val track: DiscoTrack
                if(allFilled){
                    track = DiscoTrack(albumID = album.id, albumSide = side, trackNum = trackNumber.toInt(), title = title, lengthMin = lengthMins.toInt(), lengthSec = lengthSecs.toInt())
                } else {
                    track = DiscoTrack(albumID = album.id, albumSide = true, trackNum = 0, title = title, lengthMin = 0, lengthSec = 0)

                }

                //create button
                Button(onClick = { onClick(track)}, enabled = allFilled) {
                    Text(text = stringResource(R.string.save_track_button), textAlign = TextAlign.Center)
                }
            }
        }
    }
}