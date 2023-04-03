package com.csci448.elibillinger_A2.quizler.ui.question

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
import com.csci448.elibillinger_A2.quizler.R
import com.csci448.elibillinger_A2.quizler.data.QuestionType
import com.csci448.elibillinger_A2.quizler.data.QuizViewModel
import com.csci448.elibillinger_A2.quizler.data.QuizViewModelFactory
import com.csci448.elibillinger_A2.quizler.databinding.FragmentQuestionBinding

class QuestionFragment : Fragment() {
    private lateinit var quizViewModel: QuizViewModel
    private var _binding: FragmentQuestionBinding? = null
    private val binding get() = _binding!!
    private var questionsAnswered = ArrayList<Int>()
    private var questionsCheated = ArrayList<Int>()
    private var numCheats = 3

    companion object {
        private const val LOG_TAG = "448.QuestionFragment"
        private const val KEY_INDEX = "index"
        private const val KEY_SCORE = "score"
        private const val KEY_QUESTION = "answered questions"
        private const val KEY_CHEAT = "questions cheated"
    }

    private fun updateQuestion() {
        checkCheated()
        checkAnsweredQuestions()
        setCurrentScoreText()
        binding.questionTextView.text = resources.getString(quizViewModel.currentQuestionTextId)
        if(quizViewModel.currentQuestionType == QuestionType.TF){
            if(quizViewModel.hasQuestionBeenAnswered){
                binding.falseButton.isEnabled = false
                binding.trueButton.isEnabled = false
            } else {
                binding.falseButton.isEnabled = true
                binding.trueButton.isEnabled = true
            }
            binding.falseButton.visibility = View.VISIBLE
            binding.trueButton.visibility = View.VISIBLE
            binding.etFillAnswer.visibility = View.GONE
            binding.submitButton.visibility = View.GONE
            binding.multiple1Button.visibility = View.GONE
            binding.multiple2Button.visibility = View.GONE
            binding.multiple3Button.visibility = View.GONE
            binding.multiple4Button.visibility = View.GONE
        } else if(quizViewModel.currentQuestionType == QuestionType.FILL){
            binding.submitButton.isEnabled = !quizViewModel.hasQuestionBeenAnswered
            binding.falseButton.visibility = View.GONE
            binding.trueButton.visibility = View.GONE
            binding.etFillAnswer.visibility = View.VISIBLE
            binding.submitButton.visibility = View.VISIBLE
            binding.multiple1Button.visibility = View.GONE
            binding.multiple2Button.visibility = View.GONE
            binding.multiple3Button.visibility = View.GONE
            binding.multiple4Button.visibility = View.GONE
        } else {
            if(quizViewModel.hasQuestionBeenAnswered){
                binding.multiple1Button.isEnabled = false
                binding.multiple2Button.isEnabled = false
                binding.multiple3Button.isEnabled = false
                binding.multiple4Button.isEnabled = false
            } else {
                binding.multiple1Button.isEnabled = true
                binding.multiple2Button.isEnabled = true
                binding.multiple3Button.isEnabled = true
                binding.multiple4Button.isEnabled = true
            }
            binding.falseButton.visibility = View.GONE
            binding.trueButton.visibility = View.GONE
            binding.etFillAnswer.visibility = View.GONE
            binding.submitButton.visibility = View.GONE
            binding.multiple1Button.visibility = View.VISIBLE
            binding.multiple2Button.visibility = View.VISIBLE
            binding.multiple3Button.visibility = View.VISIBLE
            binding.multiple4Button.visibility = View.VISIBLE
            binding.multiple1Button.text = resources.getString(quizViewModel.currentQuestionChoice1)
            binding.multiple2Button.text = resources.getString(quizViewModel.currentQuestionChoice2)
            binding.multiple3Button.text = resources.getString(quizViewModel.currentQuestionChoice3)
            binding.multiple4Button.text = resources.getString(quizViewModel.currentQuestionChoice4)
        }
    }

    private fun setCurrentScoreText() {
        binding.scoreTextView.text = quizViewModel.currentScore.toString()
    }

    private fun checkAnsweredQuestions(){
        questionsAnswered.forEach {
            if(it == quizViewModel.currentIndex){
                quizViewModel.updateAnsweredQuestions()
            }
        }
    }

    private fun checkCheated(){
        questionsCheated.forEach {
            if(it == quizViewModel.currentIndex){
                quizViewModel.userCheated()
            }
        }
    }

    private fun checkAnswer(guess: String) {
        if(quizViewModel.didUserCheat){
            Toast.makeText(requireContext(), R.string.cheat_toast, Toast.LENGTH_SHORT).show()
            quizViewModel.isAnswerCorrect(guess)
        } else {
            if (quizViewModel.isAnswerCorrect(guess)) {
                Toast.makeText(requireContext(), R.string.correct_toast, Toast.LENGTH_SHORT).show()
                setCurrentScoreText()
            } else {
                if(quizViewModel.didUserCheat){
                    Toast.makeText(requireContext(), R.string.cheat_toast, Toast.LENGTH_SHORT).show()
                } else {
                Toast.makeText(requireContext(), R.string.incorrect_toast, Toast.LENGTH_SHORT).show()
                setCurrentScoreText()
                }
            }
        }
        updateQuestion()
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
        questionsAnswered = savedInstanceState?.getIntegerArrayList(KEY_QUESTION) ?: ArrayList<Int>()
        questionsCheated = savedInstanceState?.getIntegerArrayList(KEY_CHEAT) ?: ArrayList<Int>()
        val factory = QuizViewModelFactory(currentIndex,currentScore) //start with the first question and no score
        quizViewModel = ViewModelProvider(requireActivity(), factory).get(factory.getViewModelClass())


        _binding = FragmentQuestionBinding.inflate(inflater, container, false)
        return binding.root
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        Log.d(LOG_TAG, "onViewCreated() called")
        updateQuestion()
        binding.trueButton.setOnClickListener { checkAnswer(true.toString())}
        binding.falseButton.setOnClickListener { checkAnswer(false.toString())}
        binding.submitButton.setOnClickListener { checkAnswer(binding.etFillAnswer.text.toString()) }
        binding.previousButton.setOnClickListener { moveToQuestion(-1)}
        binding.nextButton.setOnClickListener { moveToQuestion(1) }
        binding.multiple1Button.setOnClickListener { checkAnswer(1.toString()) }
        binding.multiple2Button.setOnClickListener { checkAnswer(2.toString()) }
        binding.multiple3Button.setOnClickListener { checkAnswer(3.toString()) }
        binding.multiple4Button.setOnClickListener { checkAnswer(4.toString()) }
        binding.cheatButton.setOnClickListener {
            if(numCheats > 0) {
                numCheats--
                view.findNavController()
                    .navigate(
                        QuestionFragmentDirections.actionQuestionFragmentToCheatFragment(
                            quizViewModel.currentQuestionAnswer
                        )
                    )
            }
        }
    }

    override fun onSaveInstanceState(savedInstanceState: Bundle) {
        savedInstanceState.putInt(KEY_INDEX,quizViewModel.currentIndex)
        savedInstanceState.putInt(KEY_SCORE,quizViewModel.currentScore)
        savedInstanceState.putIntegerArrayList(KEY_QUESTION,quizViewModel.answeredQuestions)
        savedInstanceState.putIntegerArrayList(KEY_CHEAT,quizViewModel.cheatQuestions)
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