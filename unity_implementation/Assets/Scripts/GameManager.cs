using UnityEngine;

public class GameManager : MonoBehaviour
{
    public int player1Score, player2Score;
    public ScoreText scoreTextLeft, scoreTextRight;

    public void OnScoreZoneReached(int id)
    {
        if (id == 1)
        {
            player1Score++;
            scoreTextLeft.SetScore(player1Score);
        }
        
        if (id == 2)
        {
            player2Score++;
            scoreTextRight.SetScore(player2Score);
        }
    }
}
