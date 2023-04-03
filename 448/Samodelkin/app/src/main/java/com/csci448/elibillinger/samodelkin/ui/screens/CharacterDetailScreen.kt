package com.csci448.elibillinger.samodelkin.ui.screens

import androidx.compose.foundation.layout.*
import androidx.compose.material.Divider
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.csci448.elibillinger.samodelkin.R
import com.csci448.elibillinger.samodelkin.data.SamodelkinCharacter
import com.csci448.elibillinger.samodelkin.ui.theme.Purple200
import com.csci448.elibillinger.samodelkin.ui.theme.SamodelkinTheme
import com.csci448.elibillinger.samodelkin.util.CharacterGenerator
import java.io.Serializable

@Composable
private fun StatsDisplay(name: String, value: String){
    Row {
        Text(text = name,modifier = Modifier.weight(1.0f))
        Text(text = value, modifier = Modifier.weight(1.0f))
    }
}

@Composable
private fun SectionHeader(title: String){
    Column{
        Text(text = title, fontSize = 24.sp)
        Divider(thickness = 2.dp, color = Purple200)
    }
}

@Composable
private fun StatsSection(dexterity: String, strength: String, wisdom: String){
    Column{
        SectionHeader(title = stringResource(R.string.stats_label))
        StatsDisplay(name = stringResource(R.string.dex_label), value = dexterity)
        StatsDisplay(name = stringResource(R.string.str_label), value = strength)
        StatsDisplay(name = stringResource(R.string.wis_label), value = wisdom)
    }
}

@Composable
private fun RaceSection(race: String){
    Column{
        SectionHeader(stringResource(R.string.race_label))
        Text(race)
    }
}

@Composable
private fun NameSection(name: String){
    Column {
        SectionHeader(stringResource(R.string.name_label))
        Text(name)
    }
}


@Composable
public fun CharacterDetailScreen(character : SamodelkinCharacter) {
    Column(Modifier.padding(16.dp)) {
        NameSection(character.name)
        Spacer(modifier = Modifier.height(16.dp))
        RaceSection(character.race)
        Spacer(modifier = Modifier.height(16.dp))
        StatsSection(character.dex, character.str, character.wis )
    }
}

@Preview(showBackground = true)
@Composable
private fun PreviewCharacterDetailScreen(){
    SamodelkinTheme {
        CharacterDetailScreen(CharacterGenerator.generateRandomCharacter())
    }
}