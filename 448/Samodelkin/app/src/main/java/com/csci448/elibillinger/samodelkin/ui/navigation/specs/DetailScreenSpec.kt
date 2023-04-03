package com.csci448.elibillinger.samodelkin.ui.navigation.specs

import android.util.Log
import androidx.compose.runtime.Composable
import androidx.compose.runtime.livedata.observeAsState
import androidx.navigation.*
import com.csci448.elibillinger.samodelkin.R
import com.csci448.elibillinger.samodelkin.ui.screens.CharacterDetailScreen
import com.csci448.elibillinger.samodelkin.viewmodels.ISamodelkinCharacterViewModel
import java.util.*

object DetailScreenSpec: IScreenSpec {
    override val title = R.string.app_name
    private var id = "id"
    override var route = "detail/{id}"
    override val arguments: List<NamedNavArgument> = listOf(
        navArgument("id") {type = NavType.StringType}
    )

    override fun navigateTo( vararg args: String?): String {
        route = "detail/".plus(args[0].toString())
        id = args[0].toString()
        return route
    }

    @Composable
    override fun TopAppBarActions(navController: NavController) {
        //nothing
    }

    @Composable
    override fun Content(viewModel: ISamodelkinCharacterViewModel,
                         navController: NavController,
                         navBackStackEntry: NavBackStackEntry
    ){
        val arg = navBackStackEntry.arguments?.getString("id","") ?: ""
        val characterState = viewModel.characterLiveData.observeAsState()
        viewModel.loadCharacter(UUID.fromString(arg))
        characterState.value?.let {
            CharacterDetailScreen(character = it)
        }
    }
}