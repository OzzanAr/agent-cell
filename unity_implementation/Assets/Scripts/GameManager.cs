using System;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public static GameManager instance;

    public int player1Score, player2Score;
    public ScoreText scoreTextLeft, scoreTextRight;
    public Action onReset;

    private void Awake()
    {
        if (instance)
        {
            Destroy(gameObject);
        }
        else
        {
            instance = this;
        }
    }

    public void OnScoreZoneReached(int id)
    {
        onReset?.Invoke();

        if (id == 1)
        {
            player1Score++;
            scoreTextLeft.SetScore(player1Score);
            scoreTextLeft.Highlight();
        }
        
        if (id == 2)
        {
            player2Score++;
            scoreTextRight.SetScore(player2Score);
            scoreTextRight.Highlight();
        }
    }

}
