using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class Controller : MonoBehaviour
{

    private bool Working;

    private Dictionary<string, string> Map;

    private bool[] States;

    public GameObject[] LEDGO;
    public GameObject[] SEGGO;

    public GameObject TextGO;

    private Led[] LED;
    private Seg[] SEG;
    private Text Text;

    // Use this for initialization
    void Start()
    {
        States = new bool[8];
        LED = new Led[8];
        SEG = new Seg[8];
        for (int i = 0; i < 8; i++)
        {
            LED[i] = LEDGO[i].GetComponent<Led>();
            SEG[i] = SEGGO[i].GetComponent<Seg>();
        }

        Text = TextGO.GetComponent<Text>();
    }

    internal void Compile()
    {
        StartCoroutine(Upload());
    }

    IEnumerator Upload()
    {
        Dictionary<string, string> formData = new Dictionary<string, string>
        {
            { "code", Text.text }
        };

        UnityWebRequest www = UnityWebRequest.Post("/compile", formData);
        yield return www.SendWebRequest();

        if (www.isNetworkError || www.isHttpError)
        {
            Debug.Log(www.error);
        }
        else
        {
            Working = true;

            Map = new Dictionary<string, string>();

            string[] result = www.downloadHandler.text.Replace("{", "").Replace("}", "").Split(',');
            for (int i = 0; i < result.Length; i++)
            {
                string[] keyValue = result[i].Split('=');
                Map.Add(keyValue[0].Trim(), keyValue[1].Trim());
            }
        }
    }

    internal void SwitchChanged(int index, bool state)
    {
        States[index] = state;

        if (Working)
        {
            string input = "";
            for (int i = 0; i < States.Length; i++)
            {
                input += States[i] ? 1 : 0;
            }

            string output = Map[input];

            for (int i = 0; i < 8; i++)
            {
                LED[i].ChangeState(output[i] == '1' ? true : false);
            }
            for (int i = 8; i < 16; i++)
            {
                SEG[i - 8].ChangeState(output[i] == '1' ? true : false);
            }
        }
    }
}
