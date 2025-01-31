using UnityEngine;

public class Ball : MonoBehaviour
{
    public GameManager manager;
    public Rigidbody2D rb2d;
    public float maxInitalAngel = 0.8f;
    public float movementSpeed = 4.0f;
    public float maxStartY = 6f;
    public float speedMulti = 1.2f;

    private float startX = 0f;

    private void Start()
    {
        InitPush();
    }

    private void InitPush()
    {
        Vector2 direction = Random.value < 0.5f ? Vector2.left : Vector2.right;

        direction.y = Random.Range(-maxInitalAngel, maxInitalAngel);
        rb2d.linearVelocity = direction * movementSpeed;
    }

    private void ResetBall()
    {
        float postitonY = Random.Range(-maxStartY, maxStartY);
        Vector2 position = new Vector2(startX, postitonY);
        transform.position = position;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        ScoreZone scoreZone = collision.GetComponent<ScoreZone>();

        if (scoreZone)
        {
            manager.OnScoreZoneReached(scoreZone.id);
            ResetBall();
            InitPush();
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        Paddle paddle = collision.collider.GetComponent<Paddle>();

        if (paddle)
        {
            rb2d.linearVelocity *= speedMulti;
        }
    }
}
