﻿using System;
using System.Drawing;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class AddForm : Form
    {
        public Exam Result;
        public string imageName;

        public AddForm()
        {
            InitializeComponent();
        }

        private void pictureBox_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                imageName = dialog.FileName;
                try
                {
                    pictureBox.Image = Image.FromFile(imageName);
                }
                catch (OutOfMemoryException) { return; }
            }
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            if (lastNameTextBox.Text == "" ||
                firstNameTextBox.Text == "" ||
                markTextBox.Text == "" ||
                questionsTextBox.Text == "")
            {
                MessageBox.Show("Необходимо заполнить все поля!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            if (pictureBox.Image == null)
            {
                MessageBox.Show("Вставьте картинку!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            if (MainForm.IsInt(lastNameTextBox.Text) ||
                MainForm.IsInt(firstNameTextBox.Text))
            {
                MessageBox.Show("В поле 'Фамилия' или 'Имя' содержатся цифры!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            try
            {
                Convert.ToInt32(markTextBox.Text);
            }
            catch
            {
                MessageBox.Show("Поле 'Оценка' введено не верно!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            Result = new Exam(
                firstNameTextBox.Text,
                lastNameTextBox.Text,
                DateTime.Now,
                Convert.ToInt32(markTextBox.Text),
                questionsTextBox.Text,
                imageName
            );

            DialogResult = DialogResult.OK;
            Close();
        }
    }
}