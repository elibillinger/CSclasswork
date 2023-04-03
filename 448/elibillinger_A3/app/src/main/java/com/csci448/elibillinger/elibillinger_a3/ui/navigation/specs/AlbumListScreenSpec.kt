package com.csci448.elibillinger.elibillinger_a3.ui.navigation.specs

import androidx.compose.material.Icon
import androidx.compose.material.IconButton
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.AddCircle
import androidx.compose.runtime.Composable
import androidx.compose.runtime.livedata.observeAsState
import androidx.compose.ui.res.stringResource
import androidx.navigation.NamedNavArgument
import androidx.navigation.NavBackStackEntry
import androidx.navigation.NavController
import com.csci448.elibillinger.elibillinger_a3.R
import com.csci448.elibillinger.elibillinger_a3.data.DiscoAlbum
import com.csci448.elibillinger.elibillinger_a3.ui.screens.AlbumListScreen
import com.csci448.elibillinger.elibillinger_a3.viewmodels.IDiscoViewModel

object AlbumListScreenSpec: IScreenSpec {
    override val title = R.string.app_title
    override val route = "albums"
    override val arguments: List<NamedNavArgument> = listOf()

    override fun navigateTo(vararg args: String?): String {
        return route
    }

    @Composable
    override fun TopAppBarActions(navController: NavController) {
        IconButton(onClick = { navController.navigate("newAlbum") }) {
            Icon(imageVector = Icons.Filled.AddCircle, contentDescription = stringResource(id = R.string.menu_add_album_desc ))
        }
    }

    @Composable
    override fun Content(
        viewModel: IDiscoViewModel,
        navController: NavController,
        navBackStackEntry: NavBackStackEntry
    ) {
        //get the list of albums
        val albumState = viewModel.albumListLiveData.observeAsState()
        albumState.value?.let {
            AlbumListScreen(albums = it, onSelectAlbum = fun(album: DiscoAlbum){
                navController.navigate(AlbumDetailScreenSpec.navigateTo(album.id.toString()))
            })
        }
    }


}