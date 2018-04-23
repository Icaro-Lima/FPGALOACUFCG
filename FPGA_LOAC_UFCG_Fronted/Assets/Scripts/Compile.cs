using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Compile : MonoBehaviour {

    public GameObject ControllerGO;

    private Controller Controller;

	// Use this for initialization
	void Start () {
        Controller = ControllerGO.GetComponent<Controller>();

        Button btn = GetComponent<Button>();
        btn.onClick.AddListener(TaskOnClick);
    }

    void TaskOnClick()
    {
        Controller.Compile();
    }
}
