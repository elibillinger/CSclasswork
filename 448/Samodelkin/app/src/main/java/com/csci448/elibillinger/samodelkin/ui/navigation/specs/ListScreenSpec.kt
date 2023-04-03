package com.csci448.elibillinger.samodelkin.ui.navigation.specs

import android.util.Log
import androidx.compose.material.Icon
import androidx.compose.material.IconButton
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.AddCircle
import androidx.compose.runtime.Composable
import androidx.compose.runtime.livedata.observeAsState
import androidx.compose.ui.res.stringResource
import androidx.navigation.*
import com.csci448.elibillinger.samodelkin.R
import com.csci448.elibillinger.samodelkin.data.SamodelkinCharacter
import com.csci448.elibillinger.samodelkin.ui.screens.CharacterListScreen
import com.csci448.elibillinger.samodelkin.viewmodels.ISamodelkinCharacterViewModel

object ListScreenSpec: IScreenSpec {
    override val title = R.string.app_name
    override val route = "list"
    override val arguments: List<NamedNavArgument> = listOf()

    override fun navigateTo( vararg args: String?): String {
        return route
    }

    @Composable
    override fun TopAppBarActions(navController: NavController) {
        IconButton(onClick = { navController.navigate("new") }) {
            Icon(imageVector = Icons.Filled.AddCircle, contentDescription = stringResource(id = R.string.menu_add_character_desc ))
        }
    }

    @Composable
    override fun Content(viewModel: ISamodelkinCharacterViewModel,
                         navController: NavController,
                         navBackStackEntry: NavBackStackEntry
    ){
        val characterState = viewModel.characterListLiveData.observeAsState()
        characterState.value?.let { it ->

            CharacterListScreen(it, onSelectCharacter = fun(character: SamodelkinCharacter){
                navController.navigate(DetailScreenSpec.navigateTo(character.id.toString() ))
                //Log.d("TAG","Test")
            })
        }

    }


}