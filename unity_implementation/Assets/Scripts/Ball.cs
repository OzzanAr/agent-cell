using UnityEngine;

public class Ball : MonoBehaviour
{
    public Rigidbody2D rgdb2D;
    public float maxInitalAngel = 0.8f;
    public float movementSpeed = 4.0f;
    public float maxStartY = 6f;

    private float startX = 0f;

    private void Start()
    {
        InitPush();
    }

    private void InitPush()
    {
        Vector2 direction = Random.value < 0.5f ? Vector2.left : Vector2.right;

        direction.y = Random.Range(-maxInitalAngel, maxInitalAngel);
        rgdb2D.linearVelocity = direction * movementSpeed;
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
            ResetBall();
            InitPush();
        }
    }
}
