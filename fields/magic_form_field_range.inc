<?php

class magic_form_field_range extends magic_form_field {
  private $min;
  private $max;
  private $step;
  private $unit;
  private $options;
  private $option;
  /*private $show_tooltip;
  private $show_increments;
  private $show_min;
  private $show_max;*/

  /**
   * @param null $name Internal Name for this field
   * @param null $label Visible Name for this field
   * @param null $value Default or Initial Value
   *
   * @return magic_form_field_range
   */
  public static function factory($name = null, $label = null, $value = null) {
    return parent::factory($name, $label, $value);
  }

  public function __post_construct(){

  }

  public function set_options($options){
   $this->options = $options;
   return $this;
  }

  public function get_option($option){
    return $this->options[$option];
  }

  public function set_min($min){
    $this->min = $min;
    return $this;
  }

  public function get_min(){
    return $this->min;
  }


  public function set_max($max){
    $this->max = $max;
    return $this;
  }

  public function get_max(){
    return $this->max;
  }


  public function set_step($step){
    $this->step = $step;
    return $this;
  }

  public function get_step(){
    return $this->step;
  }

  public function set_increments($increments){
    asort($increments);
    $this->increments = $increments;
    return $this;
  }
  public function get_increments(){
    return (isset($this->increments) ? $this->increments : false);
  }
  public function set_unit($unit){
    $this->unit = $unit;
    return $this;
  }

  public function get_unit(){
    return $this->unit;
  }

  public function __toString() {
    $view = new StdClass();
    $view->field = $this;
    return $this->render("form.range.phtml", $view, $this->get_scope() instanceof magic_form ? $this->get_scope()->get_templates_directory(): 'templates_bootstrap');
  }

}