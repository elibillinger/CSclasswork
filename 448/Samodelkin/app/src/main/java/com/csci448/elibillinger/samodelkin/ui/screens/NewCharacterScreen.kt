package com.csci448.elibillinger.samodelkin.ui.screens

import android.content.res.Configuration
import androidx.compose.foundation.layout.*
import androidx.compose.material.Button
import androidx.compose.material.Card
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.MutableState
import androidx.compose.runtime.State
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.saveable.rememberSaveable
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalConfiguration
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Devices
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.csci448.elibillinger.samodelkin.R
import com.csci448.elibillinger.samodelkin.data.SamodelkinCharacter
import com.csci448.elibillinger.samodelkin.ui.theme.SamodelkinTheme
import com.csci448.elibillinger.samodelkin.util.CharacterGenerator
import com.csci448.elibillinger.samodelkin.util.NetworkConnectionUtil

@Composable
fun NewCharacterScreen(
    characterState: MutableState<SamodelkinCharacter>,
    onGenerateRandomCharacter: () -> Unit,
    onRequestApiCharacter: () -> Unit,
    onSaveCharacter: (SamodelkinCharacter) -> Unit){
    val initialCharacter = characterState.value
    val portrait = LocalConfiguration.current.orientation == Configuration.ORIENTATION_PORTRAIT
    if(portrait) {
        Column {
            CharacterCard(characterState)
            Spacer(modifier = Modifier.height(16.dp))
            Row{
                Box(modifier = Modifier.weight(0.5f)){
                    GenerateRandomCharacterButton(
                        characterDataState = characterState,
                        onGenerateRandomCharacter = onGenerateRandomCharacter
                    )
                }
                Spacer(modifier = Modifier.padding(16.dp))
                Box(modifier = Modifier.weight(0.5f)) {
                    ApiCharacterButton(
                        characterDataState = characterState,
                        onRequestApiCharacter = onRequestApiCharacter)
                }
            }
            Spacer(modifier = Modifier.height(16.dp))
            SaveCharacterButton(characterDataState = characterState, onSaveCharacter = onSaveCharacter)
        }
    } else {
        // landscape
        Row(modifier = Modifier.padding(16.dp)) {
            Box (modifier = Modifier.fillMaxWidth(0.5f)){
                CharacterCard(characterState)
            }
            Spacer(modifier = Modifier.height(16.dp))
            Column{
                    GenerateRandomCharacterButton(
                        characterState,
                        onGenerateRandomCharacter = onGenerateRandomCharacter
                    )
                Spacer(modifier = Modifier.height(16.dp))
                    ApiCharacterButton(
                        characterDataState = characterState,
                        onRequestApiCharacter = onRequestApiCharacter)
                Spacer(modifier = Modifier.height(16.dp))
                SaveCharacterButton(characterDataState = characterState, onSaveCharacter = onSaveCharacter)
            }
        }
    }

}

@Composable
private fun CharacterCard(characterDataState: MutableState<SamodelkinCharacter>){
    Card {
        CharacterDetailScreen(characterDataState.component1())
    }
}

@Composable
private fun GenerateRandomCharacterButton(
    characterDataState: MutableState<SamodelkinCharacter>,
    onGenerateRandomCharacter: () -> Unit
){
    NewCharacterButton(text = stringResource(R.string.generate_new_random_label),

        onClicker = { onGenerateRandomCharacter()})
}

@Composable
private fun NewCharacterButton(text: String,
                               enable: Boolean = true,
                               onClicker: () -> Unit){
    Button(modifier = Modifier.fillMaxWidth(), enabled = enable ,onClick = onClicker) {
        Text(text = text, textAlign = TextAlign.Center)
    }
}

@Composable
private fun ApiCharacterButton(
    characterDataState: MutableState<SamodelkinCharacter>,
    onRequestApiCharacter: () -> Unit
) {
    NewCharacterButton(text = stringResource(R.string.api_label),
        enable = NetworkConnectionUtil
            .isNetworkAvailableAndConnected(LocalContext.current),
        onClicker = { onRequestApiCharacter() })
}

@Composable
private fun SaveCharacterButton(
    characterDataState: MutableState<SamodelkinCharacter>,
    onSaveCharacter: (SamodelkinCharacter) -> Unit
) {
    NewCharacterButton(text = stringResource(R.string.save_to_codex_label),
        enable = true,
        onClicker = {onSaveCharacter(characterDataState.value) })
}


//@Preview(showBackground = true)
//@Composable
//private fun PreviewNewCharacterScreen(){
//    SamodelkinTheme {
//        NewCharacterScreen(CharacterGenerator.placeHolderCharacter(),
//            { CharacterGenerator.generateRandomCharacter() }, {CharacterGenerator.generateRandomCharacter()},{CharacterGenerator.placeHolderCharacter()} )
//    }
//}
//
//@Preview(device = Devices.AUTOMOTIVE_1024p,
//    widthDp = 1024, heightDp = 720, showBackground = true)
//@Composable
//private fun PreviewLandscapeNewCharacterScreen(){
//    SamodelkinTheme {
//        NewCharacterScreen(CharacterGenerator.placeHolderCharacter(),
//            { CharacterGenerator.generateRandomCharacter() }, {CharacterGenerator.generateRandomCharacter() },{CharacterGenerator.placeHolderCharacter()})
//    }
//}