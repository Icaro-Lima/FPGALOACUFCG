using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Seg : MonoBehaviour
{

    public bool State;

    private SpriteRenderer SpriteRenderer;

    // Use this for initialization
    void Start()
    {
        SpriteRenderer = GetComponent<SpriteRenderer>();

        ChangeState(State);
    }

    // Update is called once per frame
    void Update()
    {

    }

    public void ChangeState(bool state)
    {
        SpriteRenderer.enabled = State = state;
    }
}
