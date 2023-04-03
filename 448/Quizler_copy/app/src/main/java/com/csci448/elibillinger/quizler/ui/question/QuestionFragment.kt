package com.csci448.elibillinger.quizler.ui.question

import android.content.Context
import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProvider
import androidx.navigation.findNavController
import com.csci448.elibillinger.quizler.R
import com.csci448.elibillinger.quizler.data.QuizViewModel
import com.csci448.elibillinger.quizler.data.QuizViewModelFactory
import com.csci448.elibillinger.quizler.databinding.FragmentQuestionBinding

class QuestionFragment : Fragment() {
    private lateinit var quizViewModel: QuizViewModel
    private var _binding: FragmentQuestionBinding? = null
    private val binding get() = _binding!!

    companion object {
        private const val LOG_TAG = "448.QuestionFragment"
        private const val KEY_INDEX = "index"
        private const val KEY_SCORE = "score"
    }

    private fun updateQuestion() {
        setCurrentScoreText()
        binding.questionTextView.text = resources.getString(quizViewModel.currentQuestionTextId)
    }

    private fun setCurrentScoreText() {
        binding.scoreTextView.text = quizViewModel.currentScore.toString()
    }

    private fun checkAnswer(guess: Boolean) {
        if(quizViewModel.didUserCheat){
            Toast.makeText(requireContext(), R.string.cheat_toast, Toast.LENGTH_SHORT).show()
        } else {
            if (quizViewModel.isAnswerCorrect(guess)) {
                Toast.makeText(requireContext(), R.string.correct_toast, Toast.LENGTH_SHORT).show()
                setCurrentScoreText()
            } else {
                Toast.makeText(requireContext(), R.string.incorrect_toast, Toast.LENGTH_SHORT)
                    .show()
                setCurrentScoreText()
            }
        }
    }

    private fun moveToQuestion(dir: Int){
        if( dir > 0){
            quizViewModel.moveToNextQuestion()
        } else if (dir < 0) {
            quizViewModel.moveToPreviousQuestion()
        }
        updateQuestion()
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
        val currentIndex = savedInstanceState?.getInt(KEY_INDEX,0) ?: 0
        val currentScore = savedInstanceState?.getInt(KEY_SCORE,0) ?: 0
        val factory = QuizViewModelFactory(currentIndex,currentScore) //start with the first question and no score
        quizViewModel = ViewModelProvider(requireActivity(), factory).get(factory.getViewModelClass())


        _binding = FragmentQuestionBinding.inflate(inflater, container, false)
        return binding.root
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        Log.d(LOG_TAG, "onViewCreated() called")

        updateQuestion()
        binding.trueButton.setOnClickListener { checkAnswer(true)}
        binding.falseButton.setOnClickListener { checkAnswer(false)}
        binding.previousButton.setOnClickListener { moveToQuestion(-1)}
        binding.nextButton.setOnClickListener { moveToQuestion(1) }
        binding.cheatButton.setOnClickListener {
            view.findNavController()
                .navigate(QuestionFragmentDirections.actionQuestionFragmentToCheatFragment(quizViewModel.currentQuestionAnswer.toString()))
        }
    }

    override fun onSaveInstanceState(savedInstanceState: Bundle) {
        savedInstanceState.putInt(KEY_INDEX,quizViewModel.currentIndex)
        savedInstanceState.putInt(KEY_SCORE,quizViewModel.currentScore)
        super.onSaveInstanceState(savedInstanceState)
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