package com.csci448.elibillinger.elibillinger_a3.ui.navigation.specs

import androidx.compose.runtime.Composable
import androidx.compose.runtime.livedata.observeAsState
import androidx.navigation.*
import com.csci448.elibillinger.elibillinger_a3.R
import com.csci448.elibillinger.elibillinger_a3.data.DiscoTrack
import com.csci448.elibillinger.elibillinger_a3.ui.screens.AddTrackScreen
import com.csci448.elibillinger.elibillinger_a3.viewmodels.IDiscoViewModel
import java.util.*

object NewTrackScreenSpec: IScreenSpec {
    override val title = R.string.app_title
    private var id = "id"
    override var route = "newTrack/{id}"
    override val arguments: List<NamedNavArgument> = listOf(
        navArgument("id") {type = NavType.StringType }
    )

    override fun navigateTo(vararg args: String?): String {
        route = "newTrack/".plus(args[0].toString())
        id = args[0].toString()
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
        //get current album
        val arg = navBackStackEntry.arguments?.getString("id","") ?: ""
        val albumState = viewModel.albumLiveData.observeAsState()
        viewModel.loadAlbum(UUID.fromString(arg))

        albumState.value?.let {
            AddTrackScreen(album = it, onClick = fun(track: DiscoTrack){
                viewModel.addTrack(track)
                navController.navigate(AlbumDetailScreenSpec.navigateTo(it.id.toString()))
            })
        }

    }
}