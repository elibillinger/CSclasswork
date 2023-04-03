package com.csci448.elibillinger.samodelkin.ui.screens

import android.util.Log
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material.Card
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.livedata.observeAsState
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.csci448.elibillinger.samodelkin.R
import com.csci448.elibillinger.samodelkin.data.SamodelkinCharacter
import com.csci448.elibillinger.samodelkin.viewmodels.PreviewSamodelkinCharacterViewModel

@Composable
private fun CharacterRow(character: SamodelkinCharacter,
                         onSelectCharacter: (SamodelkinCharacter) -> Unit){
    Card(modifier = Modifier
        .padding(start = 16.dp, end = 16.dp, top = 8.dp, bottom = 8.dp)
        .clickable { onSelectCharacter(character) }
    ){
        Column {
            Text(text = stringResource(R.string.character_name_race_formatter).format(character.name,character.race))
            Row {
                Text(text = stringResource(id = R.string.dex_short_label), modifier = Modifier.padding(end = 2.dp), color = Color.Blue)
                Text(text = character.dex, modifier = Modifier.padding(end = 50.dp))
                Text(text = stringResource(id = R.string.str_short_label), modifier = Modifier.padding(end = 2.dp), color = Color.Blue)
                Text(text = character.str, modifier = Modifier.padding(end = 50.dp))
                Text(text = stringResource(id = R.string.wis_short_label), modifier = Modifier.padding(end = 2.dp), color = Color.Blue)
                Text(text = character.wis, modifier = Modifier.padding(end = 50.dp))
            }
        }
    }
}

@Composable
fun CharacterListScreen(characters: List<SamodelkinCharacter>,
                        onSelectCharacter: (SamodelkinCharacter) -> Unit){
    LazyColumn {
        items(characters) { SamodelkinCharacter ->
                CharacterRow(character = SamodelkinCharacter, onSelectCharacter = onSelectCharacter)
            //Log.d("TAG",SamodelkinCharacter.id.toString())
        }
    }
}

@Preview (showBackground = true)
@Composable
fun PreviewCharacterListScreen(){
    val instance = PreviewSamodelkinCharacterViewModel.getInstance()
    val list by instance.characterListLiveData.observeAsState()
    list?.let { CharacterListScreen(characters = it, onSelectCharacter ={} ) }
}