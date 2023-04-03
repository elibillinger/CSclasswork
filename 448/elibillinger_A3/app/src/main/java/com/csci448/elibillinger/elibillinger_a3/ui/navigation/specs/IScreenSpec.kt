package com.csci448.elibillinger.elibillinger_a3.ui.navigation.specs

import androidx.compose.material.Icon
import androidx.compose.material.IconButton
import androidx.compose.material.Text
import androidx.compose.material.TopAppBar
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.ArrowBack
import androidx.compose.runtime.Composable
import androidx.compose.ui.res.stringResource
import androidx.navigation.NamedNavArgument
import androidx.navigation.NavBackStackEntry
import androidx.navigation.NavController
import com.csci448.elibillinger.elibillinger_a3.R
import com.csci448.elibillinger.elibillinger_a3.viewmodels.IDiscoViewModel

sealed interface IScreenSpec {
    companion object {
        val startDestiniation: String = AlbumListScreenSpec.route
        val allScreens = IScreenSpec::class.sealedSubclasses.associate { it.objectInstance?.route to it.objectInstance }
        @Composable
        fun TopBar(navController: NavController, navBackStackEntry: NavBackStackEntry?){
            val route = navBackStackEntry?.destination?.route ?: ""
            allScreens[route]?.TopAppBarContent( navController )
        }
    }


    val title: Int
    val route: String
    val arguments: List<NamedNavArgument>
    @Composable
    fun Content(viewModel: IDiscoViewModel,
                navController: NavController,
                navBackStackEntry: NavBackStackEntry
    )

    fun navigateTo(vararg args: String?):String

    @Composable
    fun TopAppBarActions(navController: NavController)

    @Composable
    private fun TopAppBarContent(navController: NavController){
        TopAppBar(
            title = { Text(stringResource(id = title)) },
            navigationIcon = if (navController.previousBackStackEntry != null) {
                {
                    IconButton(onClick = { navController.navigateUp() }) {
                        Icon(
                            imageVector = Icons.Filled.ArrowBack,
                            contentDescription = stringResource(R.string.menu_back_desc)
                        )
                    }
                }
            } else {
                null
            },
            actions = { TopAppBarActions(navController) },
        )
    }

}