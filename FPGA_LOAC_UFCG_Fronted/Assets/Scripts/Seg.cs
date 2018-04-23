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

        if (State)
        {
            SpriteRenderer.enabled = true;
        }
        else
        {
            SpriteRenderer.enabled = false;
        }
    }

    // Update is called once per frame
    void Update()
    {

    }

    public bool ChangeState()
    {
        State = !State;

        if (State)
        {
            SpriteRenderer.enabled = true;
        }
        else
        {
            SpriteRenderer.enabled = false;
        }

        return State;
    }
}
