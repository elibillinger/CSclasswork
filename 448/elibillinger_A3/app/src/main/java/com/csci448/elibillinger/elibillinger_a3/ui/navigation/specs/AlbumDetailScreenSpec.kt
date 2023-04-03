package com.csci448.elibillinger.elibillinger_a3.ui.navigation.specs

import androidx.compose.material.Icon
import androidx.compose.material.IconButton
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.AddCircle
import androidx.compose.runtime.Composable
import androidx.compose.runtime.livedata.observeAsState
import androidx.compose.ui.res.stringResource
import androidx.navigation.*
import com.csci448.elibillinger.elibillinger_a3.R
import com.csci448.elibillinger.elibillinger_a3.ui.screens.AlbumDetailScreen
import com.csci448.elibillinger.elibillinger_a3.viewmodels.IDiscoViewModel
import java.util.*

object AlbumDetailScreenSpec: IScreenSpec {
    override val title = R.string.app_title
    private var id = "id"
    override var route = "details/{id}"
    override val arguments: List<NamedNavArgument> = listOf(
        navArgument("id"){type = NavType.StringType}
    )

    override fun navigateTo(vararg args: String?): String {
        route = "details/".plus(args[0].toString())
        id = args[0].toString()
        return route
    }

    @Composable
    override fun TopAppBarActions(navController: NavController) {

        //go to new track screen
        IconButton(onClick = { navController.navigate(NewTrackScreenSpec.navigateTo(id))}) {
            Icon(imageVector = Icons.Filled.AddCircle, contentDescription = stringResource(id = R.string.menu_add_track_desc ))
        }
    }

    @Composable
    override fun Content(
        viewModel: IDiscoViewModel,
        navController: NavController,
        navBackStackEntry: NavBackStackEntry
    ) {
        //get the current album
        val arg = navBackStackEntry.arguments?.getString("id","") ?: ""
        val albumState = viewModel.albumLiveData.observeAsState()
        viewModel.loadAlbum(UUID.fromString(arg))

        val trackState = viewModel.trackListLiveData.observeAsState()

        albumState.value?.let {

            trackState.value?.let { tracks ->
                AlbumDetailScreen(album = it, tracks = tracks )

            }
            //Call screen function
        }
    }
}