package com.csci448.elibillinger.elibillinger_a3.ui.navigation.specs

import androidx.compose.runtime.Composable
import androidx.compose.runtime.livedata.observeAsState
import androidx.navigation.NamedNavArgument
import androidx.navigation.NavBackStackEntry
import androidx.navigation.NavController
import com.csci448.elibillinger.elibillinger_a3.R
import com.csci448.elibillinger.elibillinger_a3.ui.screens.TrackListScreen
import com.csci448.elibillinger.elibillinger_a3.viewmodels.IDiscoViewModel

object TrackListScreenSpec: IScreenSpec {
    override val title = R.string.app_title
    override val route = "tracks"
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
        //get both list if albums and list of tracks
        val albumState = viewModel.albumListLiveData.observeAsState()
        val trackState = viewModel.trackListLiveData.observeAsState()
        trackState.value?.let { tracks ->
            albumState.value?.let{
                TrackListScreen(tracks = tracks, albums = it)
            }

        }
    }
}