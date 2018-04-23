using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Led : MonoBehaviour {

    public bool State;

    public Sprite SpriteOn;
    public Sprite SpriteOff;

    private SpriteRenderer SpriteRenderer;

    // Use this for initialization
    void Start () {
        SpriteRenderer = GetComponent<SpriteRenderer>();

        if (State)
        {
            SpriteRenderer.sprite = SpriteOn;
        }
        else
        {
            SpriteRenderer.sprite = SpriteOff;
        }
    }
	
	// Update is called once per frame
	void Update () {
		
	}

    public void ChangeState(bool state)
    {
        State = state;

        if (State)
        {
            SpriteRenderer.sprite = SpriteOn;
        }
        else
        {
            SpriteRenderer.sprite = SpriteOff;
        }
    }
}
