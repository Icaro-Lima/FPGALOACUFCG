using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class Controller : MonoBehaviour
{

    public GameObject StatusGO;

    private Text Status;

    private bool Working;

    private Dictionary<string, string> Map;

    private bool[] States;

    public GameObject[] LEDGO;
    public GameObject[] SEGGO;

    public GameObject TextGO;
    public InputField InputFieldGO;

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
        Status = StatusGO.GetComponent<Text>();

        InputFieldGO.text = @"module Main(
  input logic [7:0] SWI,
  output logic [7:0] LED,
  output logic [7:0] SEG
);

// Seu código aqui:



endmodule";
    }

    internal void Compile()
    {
        Status.text = "Aguardando servidor...";
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

        if (www.responseCode != 200)
        {
            Status.text = www.error + "\n" + www.downloadHandler.text;
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

            Status.text = "Ok!";
        }
    }

    internal void ReloadControls()
    {
        SwitchChanged(0, States[0]);
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
