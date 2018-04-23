using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SlideSwitch : MonoBehaviour
{

    public int Index;

    public bool State;
    public Sprite SpriteOn;
    public Sprite SpriteOff;

    private SpriteRenderer SpriteRenderer;

    public GameObject ControllerGameObject;
    private Controller Controller;

    // Use this for initialization
    void Start()
    {
        SpriteRenderer = GetComponent<SpriteRenderer>();

        if (State)
        {
            SpriteRenderer.sprite = SpriteOn;
        }
        else
        {
            SpriteRenderer.sprite = SpriteOff;
        }

        Controller = ControllerGameObject.GetComponent<Controller>();
    }

    public bool ChangeState()
    {
        State = !State;

        if (State)
        {
            SpriteRenderer.sprite = SpriteOn;
        }
        else
        {
            SpriteRenderer.sprite = SpriteOff;
        }

        Controller.SwitchChanged(Index, State);

        return State;
    }

    void OnMouseDown()
    {
        ChangeState();
    }

}
