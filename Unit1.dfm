object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Menu'
  ClientHeight = 248
  ClientWidth = 384
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LablePage: TLabel
    Left = 203
    Top = 192
    Width = 6
    Height = 13
    Caption = '0'
  end
  object LabelName: TLabel
    Left = 20
    Top = 40
    Width = 34
    Height = 13
    Caption = #1041#1083#1102#1076#1086
  end
  object LabelKitchen: TLabel
    Left = 20
    Top = 80
    Width = 31
    Height = 13
    Caption = #1050#1091#1093#1085#1103
  end
  object LabelTime: TLabel
    Left = 20
    Top = 120
    Width = 110
    Height = 13
    Caption = #1042#1088#1077#1084#1103' '#1087#1088#1080#1075#1086#1090#1086#1074#1083#1077#1085#1080#1103
  end
  object LabelPrice: TLabel
    Left = 20
    Top = 163
    Width = 26
    Height = 13
    Caption = #1062#1077#1085#1072
  end
  object Label7: TLabel
    Left = 8
    Top = 199
    Width = 32
    Height = 13
    Caption = #1042#1089#1077#1075#1086':'
  end
  object LableMax: TLabel
    Left = 46
    Top = 199
    Width = 6
    Height = 13
    Caption = '0'
  end
  object EditName: TEdit
    Left = 144
    Top = 37
    Width = 121
    Height = 21
    Enabled = False
    TabOrder = 0
  end
  object EditKitchen: TEdit
    Left = 144
    Top = 77
    Width = 121
    Height = 21
    Enabled = False
    TabOrder = 1
  end
  object EditTime: TEdit
    Left = 144
    Top = 117
    Width = 121
    Height = 21
    Enabled = False
    TabOrder = 2
  end
  object EditPrice: TEdit
    Left = 144
    Top = 160
    Width = 121
    Height = 21
    Enabled = False
    TabOrder = 3
  end
  object ButtonNext: TButton
    Left = 245
    Top = 187
    Width = 20
    Height = 25
    Caption = '>'
    TabOrder = 4
    OnClick = ButtonNextClick
  end
  object ButtonBack: TButton
    Left = 144
    Top = 187
    Width = 18
    Height = 25
    Caption = '<'
    TabOrder = 5
    OnClick = ButtonBackClick
  end
  object ButtonAdd: TButton
    Left = 279
    Top = 35
    Width = 97
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 6
    Visible = False
    OnClick = ButtonAddClick
  end
  object ButtonSave: TButton
    Left = 279
    Top = 115
    Width = 97
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 7
    Visible = False
    OnClick = ButtonSaveClick
  end
  object ButtonOpen: TButton
    Left = 279
    Top = 75
    Width = 97
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100
    TabOrder = 8
    OnClick = ButtonOpenClick
  end
  object ButtonCreate: TButton
    Left = 279
    Top = 8
    Width = 97
    Height = 25
    Caption = #1057#1086#1079#1076#1072#1090#1100
    TabOrder = 9
    OnClick = ButtonCreateClick
  end
  object ButtonAccept: TButton
    Left = 144
    Top = 218
    Width = 121
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080#1079#1077#1085#1077#1085#1080#1103
    TabOrder = 10
    Visible = False
    OnClick = ButtonAcceptClick
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = '.abr'
    Filter = 'abra cadabra base|*.abr'
    Left = 280
    Top = 208
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.abr'
    Filter = 'abra cadabra base|*.abr'
    Left = 336
    Top = 208
  end
end
