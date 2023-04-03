package com.csci448.elibillinger.elibillinger_a3.ui.navigation.specs

import androidx.compose.runtime.Composable
import androidx.navigation.NamedNavArgument
import androidx.navigation.NavBackStackEntry
import androidx.navigation.NavController
import com.csci448.elibillinger.elibillinger_a3.R
import com.csci448.elibillinger.elibillinger_a3.data.DiscoAlbum
import com.csci448.elibillinger.elibillinger_a3.ui.screens.AddAlbumScreen
import com.csci448.elibillinger.elibillinger_a3.viewmodels.IDiscoViewModel

object NewAlbumScreenSpec: IScreenSpec {
    override val title = R.string.app_title
    override val route = "newAlbum"
    override val arguments: List<NamedNavArgument> = listOf()

    override fun navigateTo(vararg args: String?): String {
        return route
    }

    @Composable
    override fun TopAppBarActions(navController: NavController) {
        //nothing
    }

    @Composable
    override fun Content(
        viewModel: IDiscoViewModel,
        navController: NavController,
        navBackStackEntry: NavBackStackEntry
    ) {
        AddAlbumScreen(onClick = fun(album: DiscoAlbum){
            viewModel.addAlbum(album)
            navController.navigate(AlbumListScreenSpec.navigateTo())
        })
    }

}