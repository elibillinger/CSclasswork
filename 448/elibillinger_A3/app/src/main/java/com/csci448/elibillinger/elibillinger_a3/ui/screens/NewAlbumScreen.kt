package com.csci448.elibillinger.elibillinger_a3.ui.screens

import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.material.Button
import androidx.compose.material.OutlinedTextField
import androidx.compose.material.Text
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.text.input.KeyboardType
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.unit.dp
import com.csci448.elibillinger.elibillinger_a3.R
import com.csci448.elibillinger.elibillinger_a3.data.DiscoAlbum

@Composable
fun AddAlbumScreen(onClick: (DiscoAlbum) -> Unit){
    //Values to store text field inputs
    var artistName by remember { mutableStateOf("") }
    var title by remember { mutableStateOf("") }
    var year by remember { mutableStateOf("") }
    var allFilled : Boolean
    Column (horizontalAlignment = Alignment.CenterHorizontally,modifier = Modifier.padding(horizontal = 30.dp)) {
        //Create all text input fields
        LazyColumn (modifier = Modifier.padding(vertical = 10.dp),horizontalAlignment = Alignment.CenterHorizontally){
            item {
                OutlinedTextField(value = artistName,
                    onValueChange = {artistName = it}, label = { Text(text = stringResource(id = R.string.add_album_artist_name))})
                OutlinedTextField(value = title,
                    onValueChange = {title = it}, label = { Text(text = stringResource(id = R.string.add_album_album_title))})
                OutlinedTextField(value = year, keyboardOptions = KeyboardOptions(keyboardType = KeyboardType.Number),
                    onValueChange = {year = it}, label = { Text(text = stringResource(id = R.string.add_album_year_published))})
                Spacer(modifier = Modifier.height(20.dp))

                //check if all fields have been filled
                allFilled = artistName != "" && title != "" && year != ""

                //create the track object
                val album: DiscoAlbum
                if(allFilled){
                    album = DiscoAlbum(artistName,title,year.toInt())
                } else {
                    album = DiscoAlbum(artistName,title,0)
                }


                Button(onClick = { onClick(album)}) {
                    Text(text = stringResource(R.string.save_album_button), textAlign = TextAlign.Center)
                }
            }
        }
    }
}
