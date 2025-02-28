<section class="content container">
    <div class="row justify-content-center">
        <div class="col-lg-4 text-center">
            <h3 class="mb-4">Регистрация</h3>
            <form action="/auth/create" method="POST" class="mb-4">
                <div class="form-group">
                    <input type="text" class="form-control tooltip-input" name="fullname" value="<?if (isset($_POST["fullname"])) echo $_POST["fullname"];?>" placeholder="Введите ФИО" autocomplete="off">
                </div>
                <div class="form-group">
                    <input type="text" class="form-control tooltip-input" name="Email" value="<?if (isset($_POST["Email"])) echo $_POST["Email"];?>" placeholder="Введите E-mail" autocomplete="off">
                </div>
                <div class="form-group">
                    <input type="text" class="form-control tooltip-input" name="login" value="<?if (isset($_POST["login"])) echo $_POST["login"];?>" placeholder="Введите логин" autocomplete="off">
                </div>
                <div class="form-group">
                    <input type="password" class="form-control tooltip-input" name="password" value="<?if (isset($_POST["password"])) echo $_POST["password"];?>" placeholder="Введите пароль">
                </div>
                <button class="btn btn-primary btn-block" type="submit">Зарегистрироваться</button>
            </form>
            <a href="/auth/signin">Уже зарегистрированы?</a>
            <div class='result-block'>
                <?php 
                    if (isset($data['errors'])) {
                        if (count($data['errors']) > 0) {
                            foreach ($data['errors'] as $key => $item) {
                                echo "<p class='result-block__item error'>$item</p>";
                            }
                        }
                    }
                    if (isset($data['result']) && !$data['result']) {
                        echo "<p class='result-block__item error'>Такой E-mail или логин уже существует</p>";
                    }
                ?>
            </div>
        </div>
    </div>
</section>