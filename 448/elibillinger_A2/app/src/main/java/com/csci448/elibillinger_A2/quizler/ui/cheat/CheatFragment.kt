package com.csci448.elibillinger_A2.quizler.ui.cheat

import android.content.Context
import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProvider
import com.csci448.elibillinger_A2.quizler.data.QuizViewModel
import com.csci448.elibillinger_A2.quizler.data.QuizViewModelFactory
import com.csci448.elibillinger_A2.quizler.databinding.FragmentCheatBinding

class CheatFragment : Fragment() {
    private lateinit var quizViewModel: QuizViewModel
    private var _binding: FragmentCheatBinding? = null
    private val binding get() = _binding!!

    companion object {
        private const val LOG_TAG = "448.CheatFragment"

    }

    override fun onAttach(context: Context) {
        super.onAttach(context)
        Log.d(LOG_TAG, "onAttach() called")
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        Log.d(LOG_TAG, "onCreate() called")
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        Log.d(LOG_TAG, "onCreateView() called")
        val factory = QuizViewModelFactory(0,0) //start with the first question and no score
        quizViewModel = ViewModelProvider(requireActivity(), factory).get(factory.getViewModelClass())

        _binding = FragmentCheatBinding.inflate(inflater, container, false)
        return binding.root
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        Log.d(LOG_TAG, "onViewCreated() called")
        val answer = CheatFragmentArgs.fromBundle(requireArguments()).answer
        binding.answerTextView.text = answer
        binding.showAnswerButton.setOnClickListener {
            binding.answerTextView.visibility = View.VISIBLE
            quizViewModel.userCheated()
        }
    }

    override fun onStart() {
        super.onStart()
        Log.d(LOG_TAG, "onStart() called")
    }

    override fun onResume() {
        super.onResume()
        Log.d(LOG_TAG, "onResume() called")
    }

    override fun onPause() {
        super.onPause()
        Log.d(LOG_TAG, "onPause() called")
    }

    override fun onStop() {
        super.onStop()
        Log.d(LOG_TAG, "onStop() called")
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
        Log.d(LOG_TAG, "onDestroyView() called")
    }

    override fun onDestroy() {
        super.onDestroy()
        Log.d(LOG_TAG, "onDestroy() called")
    }

    override fun onDetach() {
        super.onDetach()
        Log.d(LOG_TAG, "onDetach() called")
    }
}