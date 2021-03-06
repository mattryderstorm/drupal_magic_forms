<?php

class magic_form_field_button extends magic_form_field {

  /**
   * @param null $name
   * @param null $label
   * @param null $value
   *
   * @return magic_form_field_button
   */
  public static function factory($name = null, $label = null, $value = null) {
    $class = get_called_class();
    if ($label === null) {
      $label = $name;
    }
    $instance = new $class($name, $label);
    return $instance;
  }

  public function __construct($name = null, $label = null) {
    $this->name = $name;
    $this->label = t($label);
  }

  public function __toString() {
    $view = new StdClass();
    $view->field = $this;
    return $this->render("form.button.phtml", $view, $this->get_scope() instanceof magic_form ? $this->get_scope()->get_templates_directory(): 'templates_bootstrap');
  }
}