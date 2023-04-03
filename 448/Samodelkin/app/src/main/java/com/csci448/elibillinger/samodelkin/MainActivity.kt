package com.csci448.elibillinger.samodelkin

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Scaffold
import androidx.compose.material.Surface
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.livedata.observeAsState
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import androidx.lifecycle.get
import androidx.navigation.compose.rememberNavController
import com.csci448.elibillinger.samodelkin.ui.navigation.SamodelkinNavHost
import com.csci448.elibillinger.samodelkin.ui.navigation.SamodelkinTopBar
import com.csci448.elibillinger.samodelkin.ui.screens.CharacterDetailScreen
import com.csci448.elibillinger.samodelkin.ui.screens.CharacterListScreen
import com.csci448.elibillinger.samodelkin.ui.theme.SamodelkinTheme
import com.csci448.elibillinger.samodelkin.util.CharacterGenerator
import com.csci448.elibillinger.samodelkin.viewmodels.ISamodelkinCharacterViewModel
import com.csci448.elibillinger.samodelkin.viewmodels.PreviewSamodelkinCharacterViewModel
import com.csci448.elibillinger.samodelkin.viewmodels.SamodelkinCharacterViewModel
import com.csci448.elibillinger.samodelkin.viewmodels.SamodelkinCharacterViewModelFactory

class MainActivity : ComponentActivity() {

    private lateinit var viewModel: SamodelkinCharacterViewModel

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val factory = SamodelkinCharacterViewModelFactory(this)
        viewModel = ViewModelProvider(this,factory).get(factory.getViewModelClass())
        setContent {
            MainActivityContent(viewModel)
        }
    }
    @Composable
    private fun MainActivityContent(viewModel: ISamodelkinCharacterViewModel){
        val navController = rememberNavController()
        SamodelkinTheme {
            Surface(
                modifier = Modifier.fillMaxSize(),
                color = MaterialTheme.colors.background
            ) {
               Scaffold(
                   topBar = {SamodelkinTopBar(navController = navController)},
                   content = {SamodelkinNavHost(navController = navController, viewModel = viewModel)},
               )
            }
        }
    }

//    @Preview(showSystemUi = true, showBackground = true)
//    @Composable
//    private fun PreviewMainActivity() {
//        val factory = SamodelkinCharacterViewModelFactory(this)
//        viewModel = ViewModelProvider(this).get(factory.getViewModelClass())
//        val navController = rememberNavController()
//        SamodelkinTheme {
//            Scaffold {
//                SamodelkinTopBar(navController = navController)
//                SamodelkinNavHost(navController = navController, viewModel = viewModel)
//            }
//        }
//    }
}



